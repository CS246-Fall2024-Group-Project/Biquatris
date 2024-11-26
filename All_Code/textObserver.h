#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "queue.h"
#include "canvas.h"
#include "player.h"

class textObserver : public Observer {
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    int width, height;

public:
    textObserver(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, int width, int height);
    void notify() override;
    ~textObserver();
};

#endif
