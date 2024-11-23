#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "queue.h"
#include "effect.h"
#include "canvas.h"
#include "level.h"
#include "shape.h"

class Player {
  protected:
    int playerID;
    int score;
    Level* level;
    Queue* queue;
    std::vector<Effect*> effects;
    Canvas* canvas;
    Shape* currentShape;

  public:
    Player(int playerID, int score, Level* level, Queue* queue, Canvas* canvas);
    void levelUp();
    void levelDown();
    int chooseLevel();
    void addScore(int points);
    int getScore() const;
    void applyEffect(Effect* effect);
    void removeEffect(Effect* effect);
    void processEffects();
    bool takeTurn(Canvas &game_board);
    void drop();
    void reset();
    bool gameOver() const;
    ~Player();
};


#endif