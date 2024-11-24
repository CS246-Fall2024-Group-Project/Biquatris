#include <iostream>
#include "canvas.h"
#include "player.h"
#include "observer.h"
#include "textObserver.h"
#include <cstdlib>
//#include "graphicsObserver.h"
using namespace std;

void welcomeMessage() {
    cout << "Welcome to Biquadris! A turn-based Tetris-inspired game." << endl;
}


int main(int argc, char *argv[]) {
    
    // command line arguments stuff ****************************
    // defaults
    bool textMode = false; // default, display txt and XWindow
    int seed = 556; // generates a random seed

    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";

    // by default level == 0
    int startLevel = 0;

    for(int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-text") {
            textMode = true;
            // Means that we will not display Xwindow

        } else if (arg == "-seed") {
            if (i + 1 < argc) {
                seed = std::atoi(argv[++i]); // Get the next argument as the seed
            } else {
                std::cerr << "Error: Missing argument for -seed\n";
                return 1;
            }

            // changes the sequence file of player 1
        } else if (arg == "-scriptfile1") {
            if (i + 1 < argc) {
                scriptfile1 = argv[++i];
            } else {
                std::cerr << "Error: Missing argument for -scriptfile1\n";
                return 1;
            }

            // changes the sequence file of player 1
        } else if (arg == "-scriptfile2") {
            if (i + 1 < argc) {
                scriptfile2 = argv[++i];
            } else {
                std::cerr << "Error: Missing argument for -scriptfile2\n";
                return 1;
            }
        } else if (arg == "-startlevel") {
            if (i + 1 < argc) {
                startLevel = std::atoi(argv[++i]); // Get the next argument as the start level
            } else {
                std::cerr << "Error: Missing argument for -startlevel\n";
                return 1;
            }
        } else {
            std::cerr << "Unknown option: " << arg << "\n";
            return 1;
        }
    }


    // creating the canvas for the players board
    // generates a random seed.
    
    welcomeMessage();

    std::srand(seed);

    // important stuff
    Canvas game_board1(15, 11);
    Canvas game_board2(15, 11);

    

    ifstream file1 {scriptfile1};
    ifstream file2 {scriptfile2};

    //Queue queue1, queue2;

    std::unique_ptr<Level> p1LVL;
    std::unique_ptr<Level> p2LVL;

    // determines the level
    if(startLevel == 0) {
        p1LVL = std::make_unique<Level0>(file1);

        p2LVL= std::make_unique<Level0>(file2);
    } else if (startLevel == 1) {
        p1LVL = std::make_unique<Level1>(file2);

        p2LVL = std::make_unique<Level1>(file1);
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
        cerr << "That is not allowed!" <<endl;
        return 1;
    }

    Queue queue1(p1LVL.get());
    Queue queue2(p2LVL.get());

    //////////////////////////////////////////////////
    /*vector<unique_ptr<Observer>> obs1;
    vector<unique_ptr<Observer>> obs2;*/

    // determine the if it is textMode or not
    if (textMode) { // textMode is true
        // ONLY DO TEXT
        
        // player1
        textObserver(game_board1, 15, 11, startLevel, 0, queue1);

        // player2
        textObserver(game_board2, 15, 11, startLevel, 0, queue2);

    } else {

        // player1
        textObserver(game_board1, 15, 11, startLevel, 0, queue1);
        // graphicObserver();

        // player2
        textObserver(game_board2, 15, 11, startLevel, 0, queue2);
        // graphicObserver();
    }

    bool gameOver = false;

    // Loop while the game is playing
    while (!gameOver) {
        cout << "Player 1's turn: " << endl;

        // PRINT BOARD

        player1.takeTurn(player1.canvas);

        if (player1.gameOver()) {
            gameOver = true;
        }

        //queue.nextShape(); // MAKE QUEUE GET NEXT SHAPE

        // PRINT BOARD

        cout << "Player 2's turn: " << endl;
        player2.takeTurn(player2.canvas);

        if (player2.gameOver()) {
            gameOver = true;
        }
    }
}