#include "textObserver.h"
#include "canvas.h"
#include "queue.h"
#include <iostream>
using namespace std;

textObserver::textObserver(Canvas *canvas, int width, int height, int level, int score, Queue *queue)
    : canvas(canvas), width(11), height(18), level(level), score(score), queue{queue} {
    canvas->attach(std::shared_ptr<Observer>(this));
}

void printBlock(int row, int column, char letter) {
    for (int i = 1; i < row; i++) {
        cout << endl;
    }
    for (int j = 1; j < column; j++) {
        cout << " ";
    }
    cout << letter;
}

void textObserver::notify(Player* player1, Player* player2) {
    //starting of the first board
    cout << " Level: " << level << endl;
    cout << " Score: " << score << endl;

    cout << "  +";
    for (int j = 0; j < width; j++) cout << "-";
    cout << "+" << endl;

    for (int i = 0; i < height; i++) {
        if (i == 3) {
            cout << "--|";
        } else {
            cout << "  |";
        }
        for (int j = 0; j < width; j++) {
            char c = player1->getCanvas().getState(i, j);
            cout << c;
        }
        if (i == 3) {
            cout << "|--";
        } else {
            cout << "|" << endl;
        }
    }

    cout << "  +";
    for (int j = 0; j < width; j++) cout << "-";
    cout << "+" << endl;

    cout << "  Next: " << endl;
    Shape *nextShape1 = player1->getQueue()->getNext();
    if (nextShape1 != nullptr) {
        for (const auto& block : nextShape1->getBlocks()) { 
            int row = block.getY();
            int column = 2 + block.getX();
            char letter = block.getC();
            printBlock(row, column, letter);
        }
    }




    // starting of the second board
    cout << "                      " <<" Level: " << level << endl;
    cout << "                      " <<" Score: " << score << endl;

    cout << "                    " << "  +";
    for (int j = 0; j < width; j++) cout << "-";
    cout << "+" << endl;

    for (int i = 0; i < height; i++) {
        if (i == 3) {
            cout << "                    " << "--|";
        } else {
            cout << "                    " << "  |";
        }
        for (int j = 0; j < width; j++) {
            char c = player2->getCanvas().getState(i, j);
            cout << c;
        }
        if (i == 3) {
            cout << "|--";
        } else {
            cout << "|" << endl;
        }
    }

    cout << "                    " << "  +";
    for (int j = 0; j < width; j++) cout << "-";
    cout << "+" << endl;

    cout << "                    " << "  Next: " << endl;
    cout << "                    ";
    Shape *nextShape2 = player2->getQueue()->getNext();
    if (nextShape2 != nullptr) {
        for (const auto& block : nextShape1->getBlocks()) { 
            int row = block.getY();
            int column = 21 + block.getX();
            char letter = block.getC();
            printBlock(row, column, letter);
        }
    }
}

textObserver::~textObserver() {
    canvas->detach(std::shared_ptr<Observer>(this));
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
