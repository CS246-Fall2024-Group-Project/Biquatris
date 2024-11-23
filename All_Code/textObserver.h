#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "queue.h"
#include "canvas.h"
#include "player.h"

class textObserver : public Observer {
    Canvas *canvas;
    int width, height, level, score;
    Queue *q;

public:
    textObserver(Canvas *canvas, int width, int height, int level, int score, Queue *q);
    void notify(Player *player1, Player *player2);
    ~textObserver();
};

#endif
