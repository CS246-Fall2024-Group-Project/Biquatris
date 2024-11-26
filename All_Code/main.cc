#include <iostream>
#include "canvas.h"
#include "player.h"
#include "observer.h"
#include "textObserver.h"
#include "shape.h"
#include "block.h"
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void welcomeMessage() {
    cout << "Welcome to Biquadris! A turn-based Tetris-inspired game." << endl;
}

int main(int argc, char *argv[]) {
    // Command line arguments
    bool textMode = false;
    int seed = 556;
    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";
    int startLevel = 0;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-text") {
            textMode = true;
        } else if (arg == "-seed" && i + 1 < argc) {
            seed = std::atoi(argv[++i]);
        } else if (arg == "-scriptfile1" && i + 1 < argc) {
            scriptfile1 = argv[++i];
        } else if (arg == "-scriptfile2" && i + 1 < argc) {
            scriptfile2 = argv[++i];
        } else if (arg == "-startlevel" && i + 1 < argc) {
            startLevel = std::atoi(argv[++i]);
        } else {
            cerr << "Unknown option: " << arg << "\n";
            return 1;
        }
    }

    welcomeMessage();
    std::srand(seed);

    Canvas game_board1(11, 18);
    Canvas game_board2(11, 18);

    ifstream file1{scriptfile1};
    ifstream file2{scriptfile2};

    std::shared_ptr<Level> p1LVL, p2LVL;
    if (startLevel == 0) {
        p1LVL = std::make_shared<Level0>(file1);
        p2LVL = std::make_shared<Level0>(file2);
    } else if (startLevel == 1) {
        p1LVL = std::make_shared<Level1>(file1);
        p2LVL = std::make_shared<Level1>(file2);
    } else if (startLevel == 2) {
        p1LVL = std::make_shared<Level2>(file1);
        p2LVL = std::make_shared<Level2>(file2);
    } else if (startLevel == 3) {
        p1LVL = std::make_shared<Level3>(file1);
        p2LVL = std::make_shared<Level3>(file2);
    } else if (startLevel == 4) {
        p1LVL = std::make_shared<Level4>(file1);
        p2LVL = std::make_shared<Level4>(file2);
    } else {
        cerr << "Invalid starting level!" << endl;
        return 1;
    }



    Queue queue1(p1LVL.get());
    Queue queue2(p2LVL.get());

    std::shared_ptr<Player> player1 = std::make_shared<Player>(1, 0, p1LVL, queue1, game_board1, queue1.getCurrent());
    std::shared_ptr<Player> player2 = std::make_shared<Player>(2, 0, p2LVL, queue2, game_board2, queue2.getCurrent());

    // observers for players
    vector<shared_ptr<Observer>> obs1;

    /*if (textMode) {
        // Can you do this??
        obs1.emplace_back(std::make_shared<textObserver>(player1, player2, 15, 11));
    } else {
        obs1.emplace_back(std::make_shared<textObserver>(player1, player2, 15, 11));

        // palce Xwindow observers here once we do that:
    }*/

    bool gameOver = false;
    int n = 0;
    while (!gameOver && n != 4) {
        cout << "Player 1's turn: " << endl;
        player1->takeTurn();
        if (player1->gameOver()) gameOver = true;

        

        cout << "Player 2's turn: " << endl;
        player2->takeTurn();
        if (player2->gameOver()) gameOver = true;
        ++n;
    }

    cout << "Game over!" << endl;
}
