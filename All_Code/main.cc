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

    Player player1(1, 0, std::move(p1LVL), queue1, game_board1, queue1.getCurrent());
    Player player2(2, 0, std::move(p2LVL), queue2, game_board2, queue2.getCurrent());

    TextObserver textDisplay(&player1, &player2, 11, 15);

    while (!player1.gameOver() && !player2.gameOver()) {
        // Player 1's turn
        bool turnEnded = false;
        while (!turnEnded) {
            turnEnded = player1.takeTurn(player2);
            textDisplay.notify();
            if (player1.gameOver()) break;
        }

        if (player1.gameOver()) break;

        // Player 2's turn
        turnEnded = false;
        while (!turnEnded) {
            turnEnded = player2.takeTurn(player1);
            textDisplay.notify();
            if (player2.gameOver()) break;
        }
    }

    if (player1.gameOver()) {
        std::cout << "Player 1 loses!" << std::endl;
    } else if (player2.gameOver()) {
        std::cout << "Player 2 loses!" << std::endl;
    }

    return 0;
    return 0;
}
