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
    next_shape->render();
}

void textObserver::notify() {
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
            char c = canvas->getState(i, j);
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

    cout << " Next: " << endl;
    display_shape(q->findNext());
}

textObserver::~textObserver() {
    canvas->detach(this);
}



/*
  Level: 2
  Score: 2
  +-----------+
  |           |
  |           |
  |           |
--+           +--
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  |           |
  +-----------+
  Next:
    L
  LLL
*/