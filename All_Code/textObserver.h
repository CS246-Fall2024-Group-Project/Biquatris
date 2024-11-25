#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"
#include "queue.h"
#include "canvas.h"
#include "player.h"

class textObserver : public Observer {
    Player* player1;
    Player *player2;
    int width, height;

public:
    textObserver(Player *p1, Player *p2, int width, int height);
    void notify() override;
    ~textObserver();
};

#endif
