#include <iostream>
#include <memory>
#include "player.h"
#include "canvas.h"
#include "queue.h"
#include "level.h"

using namespace std;

Player::Player(int playerID, int score, std::shared_ptr<Level> level, Queue& queue, Canvas& canvas, std::shared_ptr<Shape> currentShape)
    : playerID{playerID}, score{score}, level{std::move(level)}, queue{queue}, canvas{canvas}, currentShape{currentShape} {}

void Player::levelUp() {
    int dif = level->getDifficulty();
    if (dif == 0) {
        level = std::make_shared<Level1>(level->getSequence());
    } else if (dif == 1) {
        level = std::make_shared<Level2>(level->getSequence());
    } else if (dif == 2) {
        level = std::make_shared<Level3>(level->getSequence());
    } else if (dif == 3) {
        level = std::make_shared<Level4>(level->getSequence());
    } else {
        std::cerr << "Cannot level up anymore." << std::endl;
    }
}

void Player::levelDown() {
    int dif = level->getDifficulty();
    if (dif == 0) {
        std::cerr << "Cannot level down anymore." << std::endl;
    } else if (dif == 1) {
        level = std::make_shared<Level0>(level->getSequence());
    } else if (dif == 2) {
        level = std::make_shared<Level1>(level->getSequence());
    } else if (dif == 3) {
        level = std::make_shared<Level2>(level->getSequence());
    } else {
        level = std::make_shared<Level3>(level->getSequence());
    }
}

int Player::getDifficulty() const {
    return level->getDifficulty();
}

Level* Player::getLevel() const {
    return level.get();
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

Queue& Player::getQueue() const {
    return queue;
}

void Player::takeTurn() {

    // when do we check if the player loses?????

    
    while(true) {
        canvas.display();

        string command;
        cout << "Enter command (left, right, down, drop): ";
        cin >> command;
    if (command == "left") {
        auto newShape = currentShape->left();
        if (canvas.check_fit(newShape.get())) {
            currentShape = newShape;
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "right") {
        auto newShape = currentShape->right();
        if (canvas.check_fit(newShape.get())) {
            currentShape = newShape;
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "down") {
        auto newShape = currentShape->down();
        if (canvas.check_fit(newShape.get())) {
            currentShape = newShape;
        } else {
            cout << "Invalid move!" << endl;
        }
    } else if (command == "drop") {
        if (currentShape) {
            canvas.drop(currentShape);
            queue.findNext(level.get());
            break;
        } else {
            std::cerr << "No shape available to drop!" << std::endl; //keep it like this for now
        }
    }
    break;
    }

    return;
}

void Player::reset(std::shared_ptr<Level> newLevel) {
    score = 0;
    level = std::move(newLevel);
    currentShape = queue.getCurrent();
    for (int i = 0; i < canvas.getHeight(); ++i) {
        for (int j = 0; j < canvas.getWidth(); ++j) {
            canvas.setState(i, j, ' ');
        }
    }
    canvas.notifyObservers();
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
    // Automatic cleanup for unique_ptr
}
