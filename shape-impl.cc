#include <block.h>
#include <vector>

using namespace std;

int TOP_OF_SCREEN = 1;
int MIDDLE_OF_SCREEN = 6;

L::L(int startX, int startY, int turn): letter{'L'} {
    Block head = {TOP_OF_SCREEN + 1, MIDLLE_OF_SCREEN - 1, letter, turn};
    //
    // L
    Block c1 = {TOP_OF_SCREEN + 1, MIDLLE_OF_SCREEN, letter, turn};
    // 
    // LL
    Block c2 = {TOP_OF_SCREEN + 1, MIDDLE_OF_SCREEN + 1, letter, turn};
    // 
    // LLL
    Block c2 = {TOP_OF_SCREEN, MIDDLE_OF_SCREEN + 1, letter, turn};
    //   L
    // LLL
    blocks.emplace_back(head);
    blocks.emplace_back(c1);
    blocks.emplace_back(c2);
    blocks.emplace_back(c3);
}

L::clockwise() {

}
