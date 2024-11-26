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
    std::shared_ptr<Level> level;
    Queue& queue; // Pointer to Queue
    Canvas& canvas; // Reference to Canvas
    std::shared_ptr<Shape> currentShape;

  public:
    Player(int playerID, int score, std::shared_ptr<Level> level, Queue& queue, Canvas& canvas, std::shared_ptr<Shape> currentShape);

    void levelUp();
    void levelDown();
    void addScore(int points);

    int getScore() const;
    Queue& getQueue() const;
    int getDifficulty() const;
    Level* getLevel() const;

    void takeTurn();
    void reset(std::shared_ptr<Level> newLevel); // Reset with new level

    Canvas& getCanvas() const;
    bool gameOver() const;
    ~Player();
};

#endif
