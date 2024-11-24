#include <memory>
#include "level.h"
#include "shape.h"
#include "queue.h"

Queue::Queue(Level* lv): current{lv->genShape()}, next{lv->genShape()} {}

Shape* Queue::getCurrent() const {
    return current.get();
}
Shape* Queue::getNext() const {
    return next.get();
}


void Queue::findNext(Level* lv) {
    current = std::move(next);
    next = lv->genShape();
}
