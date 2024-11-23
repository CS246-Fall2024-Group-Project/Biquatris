#ifndef LEVEL_H
#define LEVEL_H

#include "shape.h"
#include <string>
#include <fstream>
#include <memory>

class Level {
    public:
        // will generate shapes based on the properties of each level
        virtual std::unique_ptr<Shape> genShapeRNG();
        virtual std::unique_ptr<Shape> genShapeFile(std::ifstream &sequence);
        // will be any additional modifiers or things levels will add
        // such as heavy and others
        //virtual void levelEffects();
        virtual ~Level() = default;
};

class Level0: public Level {
    public:
        Level0();
        std::unique_ptr<Shape> genShapeFile(std::ifstream &sequence) override;
        //void levelEffects() override; // this function will do nothing
};

class Level1: public Level {
    public:
        Level1();
        std::unique_ptr<Shape> genShapeRNG() override;
        //void levelEffects() override;
};

class Level2 : public Level {
    public:
        Level2();
        std::unique_ptr<Shape> genShapeRNG()override;
        //void levelEffects() override;
};

class Level3 : public Level {
    public:
        bool rng;
        Level3();
        std::unique_ptr<Shape> genShapeRNG() override;
        std::unique_ptr<Shape> genShapeFile(std::ifstream &sequence) override;
        //void levelEffects() override;
};

class Level4 : public Level {
    public:
        bool rng;
        Level4();
        std::unique_ptr<Shape> genShapeRNG() override;
        std::unique_ptr<Shape> genShapeFile(std::ifstream &sequence) override;
        //void levelEffects() override;
};
