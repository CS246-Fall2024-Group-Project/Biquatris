#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "level.h"
#include "shape.h"

class Queue {
    std::unique_ptr<Shape> current;
    std::unique_ptr<Shape> next;

    public:
        Queue(Level* lv);
        Shape* getCurrent() const;
        Shape* getNext() const;

        void findNext(Level* lv);
};
#endif
