#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "queue.h"
#include "effect.h"
#include "canvas.h"
#include "level.h"
using namespace std;

// This is a commnet!

Player::Player(int playerID, int score, std::unique_ptr<Level> level, std::unique_ptr<Queue> queue, std::unique_ptr<Canvas> canvas);
    : playerID{playerID}, score{score}, level{level}, queue{queue}, canvas{canvas}, currentShape{nullptr} {}

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

std::unique_ptr<Canvas> Player::getCanvas() const {
    return canvas;
}

void applyEffect(std::unique_ptr<Effect> effect) {
    if (effect == blind) {
        sharedCanvas.add_blindEffect();
    } else if (effect == heavy) {
        sharedCanvas.add_heavyEffect();
    } else {
        sharedCanvas.add_forceEffect();
    }
}

void removeEffect(std::unique_ptr<Effect> effect) {
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
        std::unique_ptr<Shape> newShape = currentShape->left();
        if (!game_board.check_fit(currentShape)) {
            cout << "Invalid move!" << endl;
        } else {
            currentShape = newShape;
        }
    } else if (command == "right") {
        std::unique_ptr<Shape> newShape = currentShape->right();

        if (!game_board.check_fit(currentShape)) {
            cout << "Invalid move!" << endl;
        } else {
            currentShape = newShape;
        }
    } else if (command == "down") {
        // runs the down command
        std::unique_ptr<Shape> newShape = currentShape->down();

        // checks if can fit?
        if (!game_board.check_fit(newShape)) {
            // does not fit
            cout << "Invalid move!" << endl;
        } else {
            // does fit, move shape down
            // replaces current with new shape
            currentShape = newShape;
        }
    } else if (command == "drop") {
        // find lowest point where this shape can be dropped
        if (!game_board.drop(currentShape)) {
            cout << "Cannot drop shape here!" << endl;
            return false;
        }
        game_board.drop(currentShape);
        return true;
    }

    return false;
}

void reset() {
    score = 0;
    level = 0;
    effects.clear();
    currentShape = nullptr;

    // needs to loop through all of the vectors and replace everything with '_'
}

bool Player::gameOver() const {
    if (!canvas->check_fit(currentShape)) {
        return true;
    }
    return false;
}

Player::~Player() {
    for (auto* effect : effects) {
        delete effect;
    }
}
