#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "subject.h"
#include "shape.h"
#include "block.h"

class Canvas : public Subject {
    std::vector<std::vector<char>> canvas;
    int width;
    int height;

  public:
    Canvas(int width, int height);
    char getState(int row, int col) const;
    void setState(int row, int col, char c);
    bool check_fit(Shape *shape) const;
    bool drop(Shape *shape);
    void clearLine();
    void display() const;
    ~Canvas() = default;
};

#endif
