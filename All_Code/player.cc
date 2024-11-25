#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "queue.h"
#include "player.h"
//#include "effect.h"
#include "canvas.h"
#include "level.h"
using namespace std;

// This is a commnet!

Player::Player(int playerID, int score, std::unique_ptr<Level> level, Queue queue, Canvas canvas, Shape* currentShape)
    : playerID{playerID}, score{score}, level{std::move(level)}, queue{queue}, canvas{canvas}, currentShape{currentShape} {}

void Player::levelUp() {
    int dif = level->getDifficulty();
    if (dif == 0) {
        level = std::make_unique<Level1>(level->getSequence());
    } else if (dif == 1) {
        level = std::make_unique<Level2>(level->getSequence());
    } else if (dif == 2) {
        level = std::make_unique<Level3>(level->getSequence());
    } else if (dif == 3) {
        level = std::make_unique<Level4>(level->getSequence());
    } else {
        std::cerr << "Cannot level up anymore." << std::endl;
    }
}

void Player::levelDown() {
    int dif = level->getDifficulty();
    if (dif == 0) {
        std::cerr << "Cannot level down anymore." << std::endl;
    } else if (dif == 1) {
        level = std::make_unique<Level0>(level->getSequence());
    } else if (dif == 2) {
        level = std::make_unique<Level1>(level->getSequence());
    } else if (dif == 3) {
        level = std::make_unique<Level2>(level->getSequence());
    } else {
        level = std::make_unique<Level3>(level->getSequence());
    }
}

void Player::addScore(int points) {
    score += points;
}

int Player::getScore() const {
    return score;
}

Canvas Player::getCanvas() const {
    return canvas;
}

/*
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
*/ 

bool Player::takeTurn() {
    if (!currentShape) {
        currentShape = queue.getNext();
    }

    string command;
    cout << "Enter command (left, right, down, drop): ";
    cin >> command;

    if (command == "left") {
        std::unique_ptr<Shape> newShape = currentShape->left();
        if (!canvas.check_fit(currentShape)) {
            cout << "Invalid move!" << endl;
        } else {
            currentShape = newShape;
        }
    } else if (command == "right") {
        std::unique_ptr<Shape> newShape = currentShape->right();

        if (!canvas.check_fit(currentShape)) {
            cout << "Invalid move!" << endl;
        } else {
            currentShape = newShape;
        }
    } else if (command == "down") {
        // runs the down command
        std::unique_ptr<Shape> newShape = currentShape->down();

        // checks if can fit?
        if (!canvas.check_fit(newShape)) {
            // does not fit
            cout << "Invalid move!" << endl;
        } else {
            // does fit, move shape down
            // replaces current with new shape
            currentShape = newShape;
        }
    } else if (command == "drop") {
        // find lowest point where this shape can be dropped
        if (!canvas.drop(currentShape)) {
            cout << "Cannot drop shape here!" << endl;
            return false;
        }
        canvas.drop(currentShape);
        return true;
    }

    return false;
}

void Player::reset() {
    score = 0;
    level = 0;
    //effects->clear();
    currentShape = nullptr;

    // needs to loop through all of the vectors and replace everything with '_'
}

bool Player::gameOver() const {
    if (canvas.getState(0, 0) != ' ') {
        if (!canvas.check_fit(currentShape.get())) {
            return true;
        }
    }
    return false;
}

Player::~Player() {
    /*for (auto* effect : effects) {
        delete effect;
    }*/
}
