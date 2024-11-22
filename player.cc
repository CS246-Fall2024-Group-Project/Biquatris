#include <iostream>
#include <string>
#include <vector>
#include "queue.h"
#include "effect.h"
#include "canvas.h"
#include "level.h"
using namespace std;

Player::Player(int id, int score, Level* level, Queue* playerQueue, Canvas* sharedCanvas);
    : id{id}, score{score}, level{0}, playerQueue{playerQueue}, sharedCanvas{sharedCanvas} {}

void levelUp() {
    if (level != 4) {
        level++;
    }
}

void levelDown() {
    if (level != 0) {
        level--;
    }
}

void addScore(int points) {
    score += points;
}

int getScore() const {
    return score;
}

void applyEffect(Effect* effect) {
    if (effect == blind) {
        sharedCanvas.add_blindEffect();
    } else if (effect == heavy) {
        sharedCanvas.add_heavyEffect();
    } else {
        sharedCanvas.add_forceEffect();
    }
}

void removeEffect(Effect* effect) {
    if (effect == blind) {
        sharedCanvas.remove_blindEffect();
    } else if (effect == heavy) {
        sharedCanvas.remove_heavyEffect();
    } else {
        sharedCanvas.remove_forceEffect();
    }
}

int chooseLevel() {
    while (true) {
        int tmp;
        cin >> tmp;
        if (tmp >= 0 && tmp <= 4) {
            level = tmp;
            break;
        } else {
            cout << "Please enter a valid level." << endl;
        }
    }
}

void drop() {
    

}

void reset() {

}

~Player() = default;
