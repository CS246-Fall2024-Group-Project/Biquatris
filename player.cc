#include <iostream>
#include <string>
#include <vector>
#include "queue.h"
#include "effect.h"
#include "canvas.h"
#include "level.h"
using namespace std;

Player::Player(int playerID, int score, Level* level, Queue* queue, Canvas* canvas);
    : playerID{playerID}, score{score}, level{0}, queue{queue}, canvas{canvas}, currentShape{nullptr} {}

void levelUp() {
    if (level < 4) {
        level++;
    }
}

void levelDown() {
    if (level > 0) {
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
            return level;
        } else {
            cout << "Please enter a valid level." << endl;
        }
    }
}

bool Player::takeTurn(Canvas &game_board) {
    if (!currentShape) {
        currentShape = queue->getNext();
    }

    string command;
    cout << "Enter command (left, right, down, drop): ";
    cin >> command;

    if (command == "left") {
        currentShape->left();
        if (!game_board.check_fit(currentShape)) {
            currentShape->right();
            cout << "Invalid move!" << endl;
        }
    } else if (command == "right") {
        currentShape->right();
        if (!game_board.check_fit(currentShape)) {
            currentShape->left();
            cout << "Invalid move!" << endl;
        }
    } else if (command == "down") {
        currentShape->down();
        if (!game_board.check_fit(currentShape)) {
            currentShape->up();
            cout << "Invalid move!" << endl;
        }
    } else if (command == "drop") {
        if (!game_board.drop(currentShape)) {
            cout << "Cannot drop shape here!" << endl;
            return false; // No valid moves, game over
        }
        return true;
    } else {
        cout << "Invalid command. Try again." << endl;
    }

    return true;
}

void Player::drop() {
    if (currentShape) {
        if (canvas->drop(currentShape)) {
            currentShape = nullptr;
        } else {
            cout << "Couldn't drop a shape!" << endl;
        }
    }
}

void reset() {
    score = 0;
    level = 0;
    effects.clear();
    currentShape = nullptr;
}

bool Player::gameOver() const {
    return !canvas.check_fit(currentShape);
}

Player::~Player() {
    for (auto* effect : effects) {
        delete effect;
    }
}
