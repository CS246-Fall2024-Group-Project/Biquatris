#ifndef OBSERVER_H
#define OBSERVER_H

class Player;

class Observer {
  public:
    virtual void notify(Player* player1, Player* player2) = 0;
    virtual ~Observer() = default;
};

#endif
