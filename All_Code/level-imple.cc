#include <iostream>
#include <random>
#include <fstream>
#include <cstdlib>
#include "level.h"
#include "shape.h"

// Starting point!
const int x = 1, y = 3;

Level::Level(int diffuculty, std::ifstream& stream): difficulty{difficulty}, sequence{stream} {}

int Level::getDifficulty() const {
    return difficulty;
}

std::ifstream& Level::getSequence() const {
    return sequence;
}

Level0::Level0(std::ifstream& stream): Level(0, stream) {}

std::unique_ptr<Shape> Level0::genShapeFile() {
    std::unique_ptr<Shape> levelShapes;
    char shapeType;

    // read from file
    sequence >> shapeType;
    char shapeType;
    
    // Read each character from the file and create the corresponding shape
        std::unique_ptr<Shape> shape;
        if(sequence.eof()) {
            sequence.clear();
            // moves to beginning
            sequence.seekg(0, std::ios::beg);
            sequence >> shapeType;
        }
        // Create the shape based on the character read
        switch (shapeType) {
            case 'S':
                shape = std::make_unique<S>(x, y, 0); // You can adjust x, y, turn as needed
                break;
            case 'Z':
                shape = std::make_unique<Z>(x, y, 0);
                break;
            case 'T':
                shape = std::make_unique<T>(x, y, 0);
                break;
            case 'I':
                shape = std::make_unique<I>(x, y, 0);
                break;
            case 'O':
                shape = std::make_unique<O>(x, y, 0);
                break;
            case 'L':
                shape = std::make_unique<L>(x, y, 0);
                break;
            case 'J':
                shape = std::make_unique<J>(x, y, 0);
                break;
            default:
                std::cerr << "Unknown shape type: " << shapeType << std::endl;
                sequence >> shapeType; // go to next shape
        }
    return levelShapes;  // Return the vector of generated shapes
}

Level1::Level1(std::ifstream& stream): Level(1, stream) {}

std::unique_ptr<Shape> Level1::genShapeRNG() {
    int random = 1 + (rand() % 12);

    std::unique_ptr<Shape> shape;

    switch (random) {
        case 1: // 1/12 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 2: // 1/12 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        case 3: // 2/12 chance for L
            shape = std::make_unique<L>(x, y, 0);
            break;
        case 4:
            shape = std::make_unique<L>(x, y, 0);
            break;
        case 5: // 2/12 chance for J
            shape = std::make_unique<J>(x, y, 0);
            break;
        case 6:
            shape = std::make_unique<J>(x, y, 0);
            break;
        case 7: // 2/12 chance for T
            shape = std::make_unique<T>(x, y, 0);
            break;
        case 8:
            shape = std::make_unique<T>(x, y, 0);
            break;
        case 9: // 2/12 chance for O
            shape = std::make_unique<O>(x, y, 0);
            break;
        case 10:
            shape = std::make_unique<O>(x, y, 0);
            break;
        case 11: // 2/12 chance for I
            shape = std::make_unique<I>(x, y, 0);
            break;
        case 12:
            shape = std::make_unique<I>(x, y, 0);
            break;
        default:
            std::cerr << "Unexpected random number: " << random << std::endl;
            break;
    }

    return shape;
}

Level2::Level2(std::ifstream& stream): Level(2, stream) {}

std::unique_ptr<Shape> Level2::genShapeRNG() {
    int random = 1 + (rand() % 7);

    std::unique_ptr<Shape> shape;

    switch (random) {
        case 1: // 1/7 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 2: // 1/7 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        case 3: // 1/7 chance for L
            shape = std::make_unique<L>(x, y, 0);
            break;
        case 4: // 1/7 chance for J
            shape = std::make_unique<J>(x, y, 0);
            break;;
        case 5: // 1/7 chance for T
            shape = std::make_unique<T>(x, y, 0);
            break;
        case 6: // 1/7 chance for O
            shape = std::make_unique<O>(x, y, 0);
            break;
        case 7: // 1/7 chance for I
            shape = std::make_unique<I>(x, y, 0);
            break;
        default:
            break;
    }

    return shape;
}

Level3::Level3(std::ifstream& stream): Level(3, stream) {}

std::unique_ptr<Shape> Level3::genShapeRNG() {
    int random = 1 + (rand() % 9);

    std::unique_ptr<Shape> shape;

    switch (random) {
        case 1: // 1/9 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 2: // 1/9 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        case 3: // 1/9 chance for L
            shape = std::make_unique<L>(x, y, 0);
            break;
        case 4: // 1/9 chance for J
            shape = std::make_unique<J>(x, y, 0);
            break;;
        case 5: // 1/9 chance for T
            shape = std::make_unique<T>(x, y, 0);
            break;
        case 6: // 1/9 chance for O
            shape = std::make_unique<O>(x, y, 0);
            break;
        case 7: // 1/9 chance for I
            shape = std::make_unique<I>(x, y, 0);
            break;
        case 8: // 2/9 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 9: // 2/9 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        default:
            random = 1 + (rand() % 7);
    }

    return shape;
}

std::unique_ptr<Shape> Level3::genShapeFile() {
    std::unique_ptr<Shape> levelShapes;
    char shapeType;

    // read from file
    sequence >> shapeType;
    char shapeType;
    
    // Read each character from the file and create the corresponding shape
        std::unique_ptr<Shape> shape;
        
        // Create the shape based on the character read
        switch (shapeType) {
            case 'S':
                shape = std::make_unique<S>(x, y, 0); // You can adjust x, y, turn as needed
                break;
            case 'Z':
                shape = std::make_unique<Z>(x, y, 0);
                break;
            case 'T':
                shape = std::make_unique<T>(x, y, 0);
                break;
            case 'I':
                shape = std::make_unique<I>(x, y, 0);
                break;
            case 'O':
                shape = std::make_unique<O>(x, y, 0);
                break;
            case 'L':
                shape = std::make_unique<L>(x, y, 0);
                break;
            case 'J':
                shape = std::make_unique<J>(x, y, 0);
                break;
            default:
                sequence >> shapeType; // go to next shape
        }
    return levelShapes;  // Return the vector of generated shapes
}

Level4::Level4(std::ifstream& stream): Level(4, stream) {}

std::unique_ptr<Shape> Level3::genShapeRNG() {
    int random = 1 + (rand() % 9);

    std::unique_ptr<Shape> shape;

    switch (random) {
        case 1: // 1/9 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 2: // 1/9 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        case 3: // 1/9 chance for L
            shape = std::make_unique<L>(x, y, 0);
            break;
        case 4: // 1/9 chance for J
            shape = std::make_unique<J>(x, y, 0);
            break;;
        case 5: // 1/9 chance for T
            shape = std::make_unique<T>(x, y, 0);
            break;
        case 6: // 1/9 chance for O
            shape = std::make_unique<O>(x, y, 0);
            break;
        case 7: // 1/9 chance for I
            shape = std::make_unique<I>(x, y, 0);
            break;
        case 8: // 2/9 chance for Z
            shape = std::make_unique<Z>(x, y, 0);
            break;
        case 9: // 2/9 chance for S
            shape = std::make_unique<S>(x, y, 0);
            break;
        default:
            random = 1 + (rand() % 7);
    }

    return shape;
}

std::unique_ptr<Shape> Level3::genShapeFile() {
    std::unique_ptr<Shape> levelShapes;
    char shapeType;

    // read from file
    sequence >> shapeType;
    char shapeType;
    
    // Read each character from the file and create the corresponding shape
        std::unique_ptr<Shape> shape;
        
        // Create the shape based on the character read
        switch (shapeType) {
            case 'S':
                shape = std::make_unique<S>(x, y, 0); // You can adjust x, y, turn as needed
                break;
            case 'Z':
                shape = std::make_unique<Z>(x, y, 0);
                break;
            case 'T':
                shape = std::make_unique<T>(x, y, 0);
                break;
            case 'I':
                shape = std::make_unique<I>(x, y, 0);
                break;
            case 'O':
                shape = std::make_unique<O>(x, y, 0);
                break;
            case 'L':
                shape = std::make_unique<L>(x, y, 0);
                break;
            case 'J':
                shape = std::make_unique<J>(x, y, 0);
                break;
            default:
                sequence >> shapeType; // go to next shape
        }
    return levelShapes;  // Return the vector of generated shapes
}
