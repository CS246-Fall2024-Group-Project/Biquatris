#ifndef LEVEL_H
#define LEVEL_H

#include "shape.h"
#include <string>

class Level {
    protected:
        int difficulty;
        std::string fName;
        int blockRNG;
    public:
        // will generate shapes based on the properties of each level
        virtual Shape genShape() = 0;
        // will be any additional modifiers or things levels will add
        // such as heavy and others
        virtual void levelEffects();
        virtual ~Level() = default;
};

class Level0: public Level {
    std::string sequenceFile;
    int difficulty;

    public:
        Level0(const std::string &file);
        

};