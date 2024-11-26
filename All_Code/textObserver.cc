#include "textObserver.h"
#include "canvas.h"
#include "queue.h"
#include "effect.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(Player* p1, Player* p2, int width, int height)
    : player1{p1}, player2{p2}, width(width), height(height) {

    player1->getCanvas().attach(std::shared_ptr<Observer>(this));
    player2->getCanvas().attach(std::shared_ptr<Observer>(this));
}

void TextObserver::notify() {
    // Player 1 Board
    cout << " Level: " << player1->getDifficulty() << "         ";
    cout << "Level: " << player2->getDifficulty() << endl;
    cout << " Score: " << player1->getScore() << "         ";
    cout << "Score: " << player2->getScore() << endl;

    cout << " -----------      -----------" << endl;

    for (int i = height - 1; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < width; j++) {
            char c = player1->getCanvas().getState(i, j);

            // Check for BlindEffect on player1
            if (EffectManager::getInstance().hasEffect(*player1, "blind") &&
                i >= 3 && i <= 12 && j >= 2 && j <= 8) {
                cout << "?";
            } else {
                cout << c;
            }
        }
        cout << "|     |";
        for (int j = 0; j < width; j++) {
            char c = player2->getCanvas().getState(i, j);

            // Check for BlindEffect on player2
            if (EffectManager::getInstance().hasEffect(*player2, "blind") &&
                i >= 3 && i <= 12 && j >= 2 && j <= 8) {
                cout << "?";
            } else {
                cout << c;
            }
        }
        cout << "|" << endl;
    }

    cout << " -----------      -----------" << endl;

    // Display next shapes
    cout << " Next:            Next:" << endl;

    // Display player1's next shape
    Shape* nextShape1 = player1->getQueue().getNext();
    if (nextShape1 != nullptr) {
        for (const auto& block : nextShape1->getBlocks()) {
            int row = block.getY();
            int column = block.getX();
            // Adjust position for display
            cout << block.getC();
        }
        cout << endl;
    }

    // Display player2's next shape
    Shape* nextShape2 = player2->getQueue().getNext();
    if (nextShape2 != nullptr) {
        // Adjust position for display
        for (const auto& block : nextShape2->getBlocks()) {
            cout << block.getC();
        }
        cout << endl;
    }
}

TextObserver::~TextObserver() {
    player1->getCanvas().detach(std::shared_ptr<Observer>(this));
    player2->getCanvas().detach(std::shared_ptr<Observer>(this));
}




/*
  Level: 2            Level: 1
  Score: 2            Score: 10
  +-----------+       +-----------+   
  |           |       |           |
  |           |       |           |
  |           |       |           |
--+           +--   --+           +--
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  |           |       |           |
  +-----------+       +-----------+
  Next:               Next:
  OO                    L
  OO                  LLL

  // work with displaying the next shape better
*/
