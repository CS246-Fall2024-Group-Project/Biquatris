#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "level.h"
#include "shape.h"

class Queue {
    std::unique_ptr<Shape> current;
    std::unique_ptr<Shape> next;

public:
    explicit Queue(Level* lv);
    const Shape* getCurrent() const; // Use const Shape* to avoid implying ownership
    const Shape* getNext() const;

    void findNext(Level* lv);
};

#endif

