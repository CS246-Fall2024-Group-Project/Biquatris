#ifndef LEVEL_H
#define LEVEL_H

#include "shape.h"
#include <string>

class Level {
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
    public:
        Level0(const std::string &file);
        Shape genShape() override;
        void levelEffects() override; // this function will do nothing
};

class Level1: public Level {
    public:
        Level1();
        Shape genShape()override;
        void levelEffects() override;
};

