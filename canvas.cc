#include <iostream>
#include <vector>
#include "subject.h"
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
