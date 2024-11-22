#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "subject.h"
#include "block.h"

class Canvas : public Subject {
  private:
    std::vector<std::vector<Block*>> canvas; // The grid of blocks
    int rows, cols; // Dimensions of the canvas

  public:
    // Constructor to initialize the canvas dimensions
    Canvas(int rows, int cols);

    // Get the state of a specific block
    char getState(int row, int col) const override;

    // Update the state of a specific block
    void setState(int row, int col, Block* block);

    // Notify all observers of a change at a specific position
    void notifyObservers() override;

    // Destructor to clean up resources
    ~Canvas();
};

#endif
