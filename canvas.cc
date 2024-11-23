#include <iostream>
#include <vector>
#include "subject.h"
#include "shape.h"
#include "block.h"
#include "canvas.h"
using namespace std;

Canvas::Canvas(int width, int height) : width{width}, height{height} {
    canvas.resize(height);
    for (int i = 0; i < height; i++) {
        canvas[i].resize(width, ' '); 
    }
}

char Canvas::getState(int row, int col) const {
    return canvas[row][col];
}

bool Canvas::check_fit(Shape *shape, string dir_command, int row, int col) {
    Shape *tmp;

    if (dir_command == "left") {
        tmp = shape->left();
    } else if (dir_command == "right") {
        tmp = shape->right();
    } else if (dir_command == "down") {
        tmp = shape->down();
    } else {
        tmp = *shape;
    }

    for (const auto &block : tmp.getBlocks()) {
        int newRow = row + block.getX();
        int newCol = col + block.getY();

        if (newRow < 0 || newRow >= height - 3 || newCol < 0 || newCol >= width) {
            return false;
        }
        if (canvas[newRow][newCol] != ' ') {
            return false;
        }
    }

    return true;
}

void Canvas::setState(int row, int col, char c) {
    canvas[row][col] = c;
}

void Canvas::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; i < width; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}
