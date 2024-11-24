#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include "observer.h"

class Subject {
  protected:
    std::vector<std::shared_ptr<Observer>> observers; // List of observers

  public:
    virtual void attach(std::shared_ptr<Observer> o);
    virtual void detach(std::shared_ptr<Observer> o);
    virtual void notifyObservers() const;
    virtual char getState( int row, int col ) const = 0;
    virtual ~Subject() = default;
};

#endif
