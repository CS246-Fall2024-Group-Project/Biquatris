#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "queue.h"
#include "canvas.h"

class textObserver : public Observer {
    Canvas *canvas;
    int width, height, level, score;
    Queue *q;

public:
    textObserver(Canvas *canvas, int width, int height, int level, int score, Queue *q);
    void display_shape(Shape *next_shape);
    void notify() override;
    ~textObserver();
};

#endif
