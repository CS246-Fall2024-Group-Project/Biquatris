#include "subject.h"
#include "observer.h"
#include <memory>
#include <vector>

void Subject::attach( std::shared_ptr<Observer> o ) {
    observers.emplace_back(o);
}

void Subject::detach( std::shared_ptr<Observer> o ) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                return;
            }
        }
}

// might have some errors
void Subject::notifyObservers() const {
    for (auto& o : observers) {
        o->notify();
    }
}
