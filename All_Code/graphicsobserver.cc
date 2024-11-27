#include "graphicsobserver.h"
#include "canvas.h"
#include "queue.h"
#include "effect.h"
#include "shape.h"
#include <vector>

GraphicObserver::GraphicObserver(Player *p1, Player *p2, int width, int height)
    : player1{p1}, player2{p2}, 
      window{(width + 1) * 10 * 2 + 30, (height + 1) * 10 + 100},
      previousCanvas1(height, std::vector<char>(width, ' ')), // Initialize previous canvases
      previousCanvas2(height, std::vector<char>(width, ' ')) {

    player1->getCanvas().attach(std::shared_ptr<Observer>(this));
    player2->getCanvas().attach(std::shared_ptr<Observer>(this));

    notify();
}

void GraphicObserver::notify() {
    const int blockSize = 10; // Multiplier for size

    // Check and update player1's board
    for (int i = 0; i < player1->getCanvas().getHeight(); ++i) {
        for (int j = 0; j < player1->getCanvas().getWidth(); ++j) {
            char currentChar = player1->getCanvas().getState(i, j);
            char previousChar = previousCanvas1[i][j];

            // Update only if there's a change
            if (currentChar != previousChar) {
                int x = j * blockSize;
                int y = i * blockSize;

                // Erase the old block
                if (previousChar != ' ') {
                    window.fillRectangle(x, y, blockSize, blockSize, Xwindow::White);
                }

                // Draw the new block
                if (currentChar != ' ') {
                    int color = Xwindow::Blue; // Example: default to blue
                    if (currentChar == '?') color = Xwindow::Gray; // Blind effect
                    window.fillRectangle(x, y, blockSize, blockSize, color);
                }

                // Update the previous canvas
                previousCanvas1[i][j] = currentChar;
            }
        }
    }

    // Check and update player2's board
    for (int i = 0; i < player2->getCanvas().getHeight(); ++i) {
        for (int j = 0; j < player2->getCanvas().getWidth(); ++j) {
            char currentChar = player2->getCanvas().getState(i, j);
            char previousChar = previousCanvas2[i][j];

            // Update only if there's a change
            if (currentChar != previousChar) {
                int x = j * blockSize + (player1->getCanvas().getWidth() + 2) * blockSize; // Offset for player2
                int y = i * blockSize;

                // Erase the old block
                if (previousChar != ' ') {
                    window.fillRectangle(x, y, blockSize, blockSize, Xwindow::White);
                }

                std::unordered_map<char, int> colorMap = {
                    {'I', Xwindow::Aqua},
                    {'O', Xwindow::Yellow},
                    {'T', Xwindow::Purple},
                    {'S', Xwindow::Green},
                    {'Z', Xwindow::Red},
                    {'J', Xwindow::Blue},
                    {'L', Xwindow::Orange},
                    {'?', Xwindow::Gray} // For blind effect
                };

                // Usage in notify()
                if (currentChar != ' ') {
                    int color = (currentChar == '?') ? Xwindow::Gray : colorMap[currentChar];
                    window.fillRectangle(x, y, blockSize, blockSize, color);
                }

                // Update the previous canvas
                previousCanvas2[i][j] = currentChar;
            }
        }
    }

    // Handle changes for current shapes
    auto updateShape = [&](Player *player, std::vector<std::vector<char>> &prevCanvas, int offsetX) {
        Shape *currentShape = player->getCurrentShape().get();

        // Erase old shape
        for (int i = 0; i < player->getCanvas().getHeight(); ++i) {
            for (int j = 0; j < player->getCanvas().getWidth(); ++j) {
                if (prevCanvas[i][j] == '*') { // Use '*' to mark shape blocks
                    int x = j * blockSize + offsetX;
                    int y = i * blockSize;
                    window.fillRectangle(x, y, blockSize, blockSize, Xwindow::White);
                    prevCanvas[i][j] = ' '; // Reset to empty
                }
            }
        }

        // Draw new shape
        for (auto &block : currentShape->getBlocks()) {
            int x = block.getX() * blockSize + offsetX;
            int y = block.getY() * blockSize;
            window.fillRectangle(x, y, blockSize, blockSize, Xwindow::Green); // Green for current shape
            prevCanvas[block.getY()][block.getX()] = '*'; // Mark shape block
        }
    };

    // Update player1 and player2 current shapes
    updateShape(player1, previousCanvas1, 0);
    updateShape(player2, previousCanvas2, (player1->getCanvas().getWidth() + 2) * blockSize);
}

GraphicObserver::~GraphicObserver() {
    player1->getCanvas().detach(std::shared_ptr<Observer>(this));
    player2->getCanvas().detach(std::shared_ptr<Observer>(this));
}
