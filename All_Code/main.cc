#include <iostream>
#include "canvas.h"
#include "player.h"
using namespace std;

void welcomeMessage() {
    cout << "Welcome to Biquadris! A turn-based Tetris-inspired game." << endl;
}


int main(int argc, char *argvp[]) {
    
    // command line arguments stuff ****************************
    // defaults
    bool textMode = false;
    int seed = std::random_device
    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";
    int startLevel = 0;

    for(int i = 1; i < argc; ++i) {
        srd::string arg = argv[i];
        if (arg == "-text") {
            textMode = true;
        } else if (arg == "-seed") {
            if (i + 1 < argc) {
                seed = std::atoi(argv[++i]); // Get the next argument as the seed
            } else {
                std::cerr << "Error: Missing argument for -seed\n";
                return 1;
            }
        } else if (arg == "-scriptfile1") {
            if (i + 1 < argc) {
                scriptfile1 = argv[++i];
            } else {
                std::cerr << "Error: Missing argument for -scriptfile1\n";
                return 1;
            }
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

    Queue queue1, queue2;

    Player player1("Player 1", queue1);
    Player player2("Player 2", queue1);

    bool gameOver = false;

    if(startLevel == 0) {
        
    }


    /*cout << "Player 1, please choose your starting level: ";

    player1.chooseLevel();
    
    cout << "Player 2, please choose your starting level: ";
    player2.chooseLevel();*/

    // Loop while the game is playing
    while (!gameOver) {
        cout << "Player 1's turn: " << endl;
        player1.takeTurn(game_board1);

        if (player1.gameOver()) {
            gameOver = true;
        }

        //queue.nextShape(); // MAKE QUEUE GET NEXT SHAPE

        cout << "Player 2's turn: " << endl;
        player2.takeTurn(game_board2);

        if (player2.gameOver()) {
            gameOver = true;
        }
    }
}