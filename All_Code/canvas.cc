#include <iostream>
#include <vector>
#include "subject.h"
#include "shape.h"
#include "block.h"
#include "canvas.h"
using namespace std;

// CONCRETE SUBJECT

Canvas::Canvas(int width, int height) : width{width}, height{height} {
    canvas.resize(height);
    for (int i = 0; i < height; i++) {
        canvas[i].resize(width, ' '); 
    }
}

char Canvas::getState(int row, int col) const {
    return canvas[row][col];
}

bool Canvas::check_fit(Shape* shape) const {
    for (const auto& block : shape->getBlocks()) {
        int row = block.getX();
        int col = block.getY();
        // if it is out of bounds
        if (row < 0 || row >= height - 3 || col < 0 || col >= width) {
            return false;
        }
        // if place is occupied
        if (canvas[row][col] != ' ') {
            return false;
        }
    }
    return true;
}

bool Canvas::drop(Shape* shape) {
    std::unique_ptr<Shape> tmpShape = std::make_unique<Shape>(*shape);

    while (true) {
        std::unique_ptr<Shape> nextShape = tmpShape->down();
        if (!check_fit(nextShape.get())) {
            break;
        }

        tmpShape = std::move(nextShape);
    }

    if (!check_fit(tmpShape.get())) {
        return false;
    }

    for (const auto& block : tmpShape->getBlocks()) {
        int row = block.getX();
        int col = block.getY();
        canvas[row][col] = tmpShape->getLetter();
    }
    return true;
}

void Canvas::clearLine() {
    for (int i = 0; i < height; i++) {
        bool line_filled = true;

        for (int j = 0; j < width; j++) {
            if (canvas[i][j] == ' ') { // check if all the blocks are filled
                line_filled = false;
                break;
            }
        }
        if (line_filled == true) { // if the line is filled
            for (int k = i; k > 0; k--) { //recursively move all the blocks downwards by 1 unit
                for (int j = 0; j < width; j++) {
                    canvas[k][j] = canvas[k - 1][j]; // move the blocks downwards by 1 unit
                }
            }
        }
    }
}

void Canvas::setState(int row, int col, char c) {
    canvas[row][col] = c;
}

void Canvas::display() const {
    notifyObservers();
    for (int i = 0; i < height; i++) {
        for (int j = 0; i < width; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}
