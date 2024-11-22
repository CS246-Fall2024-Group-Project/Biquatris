#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  protected:
    std::string name;
    int score;
    int level;

  public:
    Player(const std::string &playerName, int level);
    int getScore() const;
    void setScore(int newScore);
    int getLevel() const;
    void setLevel(int newLevel);
    int chooseLevel();
    virtual ~Player() = default;
};


#endif