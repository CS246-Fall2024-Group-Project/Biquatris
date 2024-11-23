#include "textObserver.h"
#include "canvas.h"
#include "queue.h"
#include <iostream>
using namespace std;

textObserver::textObserver(Canvas *canvas, int width, int height, int level, int score, Queue *q)
    : canvas(canvas), width(11), height(18), level(level), score(score), q{q} {
    canvas->attach(this);
    
}

void textObserver::display_shape(Shape *next_shape) {
    if (!next_shape) {
        cout << "" << endl;
        return;
    }
    next_shape->display();
}

void textObserver::notify(Player *player1, Player *player2) {
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
            char c = player1->getCanvas()->getState(i, j);
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
    display_shape(player1->getQueue()->findNext());




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
            char c = player2->getCanvas()->getState(i, j);
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
    display_shape(player2->getQueue()->findNext());
}

textObserver::~textObserver() {
    canvas->detach(this);
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
    L
  LLL
*/
