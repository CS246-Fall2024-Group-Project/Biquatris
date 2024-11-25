#include "queue.h"
#include <utility>

Queue::Queue(Level* lv) 
    : current{lv->genShape()}, next{lv->genShape()} {}

const Shape* Queue::getCurrent() const {
    return current.get(); // Expose as a const pointer
}

const Shape* Queue::getNext() const {
    return next.get(); // Expose as a const pointer
}

void Queue::findNext(Level* lv) {
    current = std::move(next); // Transfer ownership of `next` to `current`
    next = lv->genShape();     // Generate a new Shape for `next`
}

