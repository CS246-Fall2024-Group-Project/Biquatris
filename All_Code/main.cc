#include <iostream>
#include "canvas.h"
#include "player.h"
#include "observer.h"
#include "textObserver.h"
//#include "graphicsObserver.h"
using namespace std;

void welcomeMessage() {
    cout << "Welcome to Biquadris! A turn-based Tetris-inspired game." << endl;
}


int main(int argc, char *argvp[]) {
    
    // command line arguments stuff ****************************
    // defaults
    bool textMode = false; // default, display txt and XWindow

    int seed = std::random_device // generates a random seed

    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";

    // by default level == 0
    int startLevel = 0;

    for(int i = 1; i < argc; ++i) {
        srd::string arg = argv[i];
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
    vector<unique_ptr<Observer>> obs;

    if(startLevel == 0) {
        Queue queue1, queue2;
        // make pointers for level0
        Player player1(1, 0,  queue1);
        Player player2(2, queue1);
    } else if {

    }

    // determine the if it is textMode or not
    if (textMode) { // textMode is true
        // ONLY DO TEXT
        
        // player1
        textObserver(game_baord1, 15, 11, startLevel, 0, queue1);

        // player2
        textObserver(game_board2, 15, 11, startLevel, 0, queue2);

    } else {

        // player1
        textObserver(game_baord1, 15, 11, startLevel, 0, queue1);
        // graphicObserver();

        // player2
        textObserver(game_board2, 15, 11, startLevel, 0, queue2);
        // graphicObserver();
    }

    bool gameOver = false;


    /*cout << "Player 1, please choose your starting level: ";

    player1.chooseLevel();
    
    cout << "Player 2, please choose your starting level: ";
    player2.chooseLevel();*/

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