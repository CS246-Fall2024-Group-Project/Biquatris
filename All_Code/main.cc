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

    Canvas game_board1(15, 11);
    Canvas game_board2(15, 11);

    ifstream file1{scriptfile1};
    ifstream file2{scriptfile2};

    std::unique_ptr<Level> p1LVL, p2LVL;
    if (startLevel == 0) {
        p1LVL = std::make_unique<Level0>(file1);
        p2LVL = std::make_unique<Level0>(file2);
    } else if (startLevel == 1) {
        p1LVL = std::make_unique<Level1>(file1);
        p2LVL = std::make_unique<Level1>(file2);
    } else if (startLevel == 2) {
        p1LVL = std::make_unique<Level2>(file1);
        p2LVL = std::make_unique<Level2>(file2);
    } else if (startLevel == 3) {
        p1LVL = std::make_unique<Level3>(file1);
        p2LVL = std::make_unique<Level3>(file2);
    } else if (startLevel == 4) {
        p1LVL = std::make_unique<Level4>(file1);
        p2LVL = std::make_unique<Level4>(file2);
    } else {
        cerr << "Invalid starting level!" << endl;
        return 1;
    }



    Queue queue1(p1LVL.get());
    Queue queue2(p2LVL.get());

    std::unique_ptr<Player> player1(1, 0, std::move(p1LVL), &queue1, game_board1, std::make_unique<Shape>(*queue1.getCurrent()));
    std::unique_ptr<Player> player2(2, 0, std::move(p2LVL), &queue2, game_board2, std::make_unique<Shape>(*queue2.getCurrent()));

    // observers for players
    vector<unique_ptr<Observer>> obs1;

    if (textMode) {
        // Can you do this??
        obs1.emplace_back(std::make_shared<textObserver>(player1.get(), 15, 11));
        obs1.emplace_back(std::make_shared<textObserver>(player2.get(), 15, 11));
    } else {
        obs1.emplace_back(std::make_shared<textObserver>(player1.get(), 15, 11));
        obs1.emplace_back(std::make_shared<textObserver>(player2.get(), 15, 11));

        // palce Xwindow observers here once we do that:
        // Xwindow
        // Xwindow
    }

    bool gameOver = false;

    while (!gameOver) {
        cout << "Player 1's turn: " << endl;
        player1->takeTurn();
        if (player1->gameOver()) gameOver = true;

        cout << "Player 2's turn: " << endl;
        player2->takeTurn();
        if (player2->gameOver()) gameOver = true;
    }

    cout << "Game over!" << endl;
    return 0;
}
