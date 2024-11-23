#include <iostream>
#include <random>
#include "level.h"
#include "shape.h"
#include <fstream>

std::unique_ptr<Shape> Level0::genShape() {
    std::unique_ptr<Shape> levelShapes;
    std::ifstream file(sequenceFile);  // Open the text file
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << sequenceFile << std::endl;
        return levelShapes;  // Return empty vector if file could not be opened
    }

    char shapeType;
    int x = 5, y = 2;  // Example starting coordinates for all shapes
    
    // Read each character from the file and create the corresponding shape
    while (file >> shapeType) {
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
                std::cerr << "Unknown shape type: " << shapeType << std::endl;
                continue;  // Skip unknown shapes
        }
    }

    file.close();  // Close the file after reading
    return levelShapes;  // Return the vector of generated shapes
}

std::unique_ptr<Shape> Level1::genShape() {
    int random = 1 + (rand() % 12);
    int x = 5;
    int y = 2;

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

std::unique_ptr<Shape> Level2::genShape() {
    int random = 1 + (rand() % 7);
    int x = 5;
    int y = 2;

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
            std::cerr << "Unexpected random number: " << random << std::endl;
            break;
    }

    return shape;
}
