#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "queue.h"
#include "canvas.h"
#include "level.h"
#include "shape.h"

class Player {
  protected:
    int playerID;
    int score;
    std::unique_ptr<Level> level;
    Queue* queue; // Pointer to Queue
    Canvas& canvas; // Reference to Canvas
    std::unique_ptr<Shape> currentShape;

  public:
    Player(int playerID, int score, std::unique_ptr<Level> level, Queue* queue, Canvas& canvas, std::unique_ptr<Shape> currentShape);

    void levelUp();
    void levelDown();
    void addScore(int points);
    int getScore() const;
    bool takeTurn();
    void reset(std::unique_ptr<Level> newLevel); // Reset with new level
    Canvas& getCanvas() const;
    bool gameOver() const;
    ~Player();
};

#endif
