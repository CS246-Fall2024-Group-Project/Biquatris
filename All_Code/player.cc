#include <iostream>
#include <memory>
#include "player.h"
#include "canvas.h"
#include "queue.h"
#include "level.h"

using namespace std;

Player::Player(int playerID, int score, std::unique_ptr<Level> level, Queue* queue, Canvas& canvas, std::unique_ptr<Shape> currentShape)
    : playerID{playerID}, score{score}, level{std::move(level)}, queue{queue}, canvas{canvas}, currentShape{std::move(currentShape)} {}

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

Canvas& Player::getCanvas() const {
    return canvas;
}

bool Player::takeTurn() {
    string command;
    cout << "Enter command (left, right, down, drop): ";
    cin >> command;

    if (command == "left") {
        auto newShape = currentShape->left();
        if (canvas.check_fit(newShape.get())) {
            currentShape = std::move(newShape);
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "right") {
        auto newShape = currentShape->right();
        if (canvas.check_fit(newShape.get())) {
            currentShape = std::move(newShape);
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "down") {
        auto newShape = currentShape->down();
        if (canvas.check_fit(newShape.get())) {
            currentShape = std::move(newShape);
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "drop") {
        canvas.drop(currentShape.get());
        currentShape = nullptr; // Shape is now on the canvas
        return true;
    }

    return false;
}

void Player::reset(std::unique_ptr<Level> newLevel) {
    score = 0;
    level = std::move(newLevel);
    currentShape = std::make_unique<Shape>(queue->getCurrent());
    // HOW DO WE RESET THE CANVAS
}

bool Player::gameOver() const {
    return !canvas.check_fit(currentShape.get());
}

Player::~Player() {
    // Automatic cleanup for unique_ptr
}
