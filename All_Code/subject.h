#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Subject {
  protected:
    std::vector<Observer*> observers; // List of observers

  public:
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
    virtual void notifyObservers(bool graphics);
    virtual char getState( int row, int col ) const = 0;
    virtual ~Subject() = default;
};

#endif
