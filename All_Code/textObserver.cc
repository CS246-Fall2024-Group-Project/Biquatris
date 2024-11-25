#include "textObserver.h"
#include "canvas.h"
#include "queue.h"
#include <iostream>
using namespace std;

textObserver::textObserver(Canvas *canvas, int width, int height, int level, int score, Queue *queue)
    : canvas(canvas), width(11), height(18), level(level), score(score), queue{queue} {
    canvas->attach(std::shared_ptr<Observer>(this));
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
    Shape *nextShape1 = player1->getQueue()->findNext();
    if (nextShape1 != nullptr) {
        nextShape1->display(); // Display the next shape directly
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
    Shape *nextShape2 = player2->getQueue()->findNext();
    if (nextShape2 != nullptr) {
        nextShape2->display(); // Display the next shape directly
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
    L                   L
  LLL                 LLL

  // work with displaying the next shape better
*/
