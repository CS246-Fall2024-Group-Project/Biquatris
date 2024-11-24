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

        if (row < 0 || row >= height - 3 || col < 0 || col >= width) {
            return false;
        }

        if (canvas[row][col] != ' ') {
            return false;
        }
    }
    return true;
}

bool Canvas::drop(Shape* shape) {
    if (!check_fit(shape)) {
        return false;
    }

    for (const auto& block : shape->getBlocks()) {
        int row = block.getX();
        int col = block.getY();
        canvas[row][col] = shape->getLetter();
    }
    return true;
}

void Canvas::setState(int row, int col, char c) {
    canvas[row][col] = c;
}

void Canvas::display(/*SHOULD TAKE IN A BOOL*/) const {

    // YOU NEED TO CALL NOTIFY OBSERVER IN HERE
    for (int i = 0; i < height; i++) {
        for (int j = 0; i < width; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}
