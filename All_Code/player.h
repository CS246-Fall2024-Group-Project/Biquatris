#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "queue.h"
//#include "effect.h"
#include "canvas.h"
#include "level.h"
#include "shape.h"

class Player {
  protected:
    int playerID;
    int score;
    std::unique_ptr<Level> level;

    Queue queue;
    //std::vector<std::unique_ptr<Effect>> effects;
    Canvas canvas;
    std::unique_ptr<Shape> currentShape;

  public:
    Player(int playerID, int score, std::unique_ptr<Level> level, Queue queue, Canvas canvas, std::unique_ptr<Shape> currentShape);

    void levelUp();
    void levelDown();
    void random();
    void noRandom();
    void addScore(int points);
    int getScore() const;
    //void applyEffect(Effect* effect);
    //void removeEffect(Effect* effect);
    void processEffects();
    bool takeTurn();
    void reset();
    Canvas getCanvas() const;
    bool gameOver() const;
    ~Player();
};


#endif
