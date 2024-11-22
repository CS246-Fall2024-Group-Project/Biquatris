#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "queue.h"
#include "effect.h"
#include "canvas.h"
#include "level.h"

class Player {
  protected:
    int playerID;
    int score;
    Level* level;
    Queue* queue;
    std::vector<Effect*> effects;
    std::vector<Effect*> powers;
    Canvas* canvas;

  public:
    Player(int id, Level* level, Queue* playerQueue, Canvas* sharedCanvas);
    void levelUp();
    void levelDown();
    int chooseLevel();
    void addScore(int points);
    int getScore() const;
    void applyEffect(Effect* effect);
    void removeEffect(Effect* effect);
    void processEffects();
    void drop();
    void reset();
    ~Player();
};


#endif