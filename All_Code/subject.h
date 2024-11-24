#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include "observer.h"

class Subject {
  protected:
    std::vector<std::unique_ptr<Observer>> observers; // List of observers

  public:
    virtual void attach(std::unique_ptr<Observer> observer);
    virtual void detach(std::unique_ptr<Observer> observer);
    virtual void notifyObservers();
    virtual char getState( int row, int col ) const = 0;
    virtual ~Subject() = default;
};

#endif
