#include "queue.h"
#include <utility>

Queue::Queue(Level* lv) 
    : current{lv->genShape()}, next{lv->genShape()} {}

Shape* Queue::getCurrent() {
    return current.get(); // Expose as a const pointer
}

Shape* Queue::getNext() {
    return next.get(); // Expose as a const pointer
}

void Queue::findNext(Level* lv) {
    current = std::move(next); // Transfer ownership of `next` to `current`
    next = lv->genShape();     // Generate a new Shape for `next`
}

