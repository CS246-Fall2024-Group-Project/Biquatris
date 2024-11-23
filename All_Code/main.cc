#include <iostream>
#include "canvas.h"
#include "player.h"
using namespace std;

void welcomeMessage() {
    cout << "Welcome to Biquadris! A turn-based Tetris-inspired game." << endl;
}

int main() {
    welcomeMessage();
    Canvas game_board(18, 11);
    Queue queue1, queue2;
    Player player1("Player 1", queue1);
    Player player2("Player 2", queue1);

    bool gameOver = false;
    cout << "Player 1, please choose your starting level: ";
    player1.chooseLevel();
    cout << "Player 2, please choose your starting level: ";
    player2.chooseLevel();
    while (!gameOver) {
        cout << "Player 1's turn: " << endl;
        player1.takeTurn(game_board);

        if (player1.gameOver()) {
            gameOver = true;
        }

        cout << "Player 2's turn: " << endl;
        player2.takeTurn(game_board);

        if (player2.gameOver()) {
            gameOver = true;
        }
    }
}