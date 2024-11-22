#include <iostream>
#include <string>
using namespace std;

Player::Player(const std::string &playerName, int level) 
    : playerName{playerName}, level{0} {}

int getScore() const {
    return score;
}

void setScore(int newScore) {
    score = newScore;
}

int getLevel() const {
    return level;
}

void setLevel(int newLevel) {
    level = newLevel;
}

int chooseLevel() {
    istream in;
    int tmp;
    in >> tmp;
    if (tmp >= 0 && tmp <= 4) {
        level = tmp;
        
    }

~Player() = default;
