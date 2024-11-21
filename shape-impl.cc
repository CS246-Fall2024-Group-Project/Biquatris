#include <block.h>
#include <shape.h>
#include <vector>

using namespace std;

int TOP_OF_SCREEN = 1;
int MIDDLE_OF_SCREEN = 6;

Shape::Shape(char letter) : letter{letter}, rotationState(1) {}

Shape::Shape(const Shape& other)
    : letter(other.letter),
      rotationState(other.rotationState),
      blocks(other.blocks) {}

char Shape::getLetter() const {
    return letter;
}
Shape Shape::left() {

}

L::L(int startX, int startY, int turn): letter{'L'}, rotationState{1} {
    // this is de default L rotation state

    // do not change
    Block head = {startX - 1, startY + 1, letter, turn};
    // 
    // L

    Block c2 = {startX, startY + 1, letter, turn};
    //
    // LL

    Block c3 = {startX + 1, startY + 1, letter, turn};
    // 
    // LLL

    Block c4 = {startX + 1, startY, letter, turn};
    //   L
    // LLL
    blocks.emplace_back(head);
    blocks.emplace_back(c2);
    blocks.emplace_back(c3);
    blocks.emplace_back(c4);

    // do not change
}

L::L(const L&other) : Shape(other) {}

std::unique_ptr<Shape> L::clockwise() {
    // axis of rotation does not change!

    int x = blocks.front().getX(); // get the x-axis of the axis
    int y = blocks.front().getY(); // get the y-axis of the axis

    L newShape(*this);
    
    // do not change
    int defaultRotation = 1;
    //   *
    // ***

    int rotation2 = 2;
    // *
    // *
    // **

    int rotation3 = 3;
    // ***
    // *

    int rotation4 = 4;
    // **
    //  *
    //  *

    if(rotationState == defaultRotation) { // default -> rotation2
        rotationState = rotation2;
        // do the math to properly rotate in in the cartiasian cordinates
        //NOTE: THE AXIS DOES NOT CHANGE FOR L!
        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);
        // LL

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 1);
        // L
        // LL

        blocks[3].setX(x + 0);
        blocks[3].setY(y - 2);
        // L
        // L
        // LL

    } else if (rotationState == rotation2) { // rotation2 -> rotation3
        rotationState = rotation3;
        // NOTE: THE AXIS DOES NOT CHANGE FOR L
        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);
        // L
        // L

        blocks[2].setX(x + 1);
        blocks[2].setY(y - 1);
        // LL
        // L

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);
        // LLL
        // L
    } else if (rotationState == rotation3) { // rotation3 -> rotation4
        rotationState = rotation4;
        // NOTE: THE HEAD WILL SHIFT OVER BY X + 1
        x += 1;
        blocks[0].setX(x);
        // y does not change
        //
        //
        //  L

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);
        //
        //  L
        //  L

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 2);
        //  L
        //  L
        //  L

        blocks[3].setX(x - 1);
        blocks[3].setY(y - 2);
        // LL
        //  L
        //  L

    } else if (rotationState == rotation4) { // rotation 4 -> defaultRotation
        rotationState = defaultRotation;
        // NOTE: THE HEAD MUST CHANGE BACK
        x -= 1;
        blocks[0].setX(x);
        //
        // L

        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);

        blocks[1].setX(x + 2);
        blocks[1].setY(y + 0);

        blocks[1].setX(x + 2);
        blocks[1].setY(y - 1);

    }
    return std::make_unique<L>(newShape);
}

std::unique_ptr<Shape> L::counter() {
    // axis of rotation does not change!

    int x = blocks.front().getX(); // get the x-axis of the axis
    int y = blocks.front().getY(); // get the y-axis of the axis

    L newShape(*this);
    
    // do not change
    int defaultRotation = 1;
    //   *
    // ***

    int rotation2 = 2;
    // *
    // *
    // **

    int rotation3 = 3;
    // ***
    // *

    int rotation4 = 4;
    // **
    //  *
    //  *

    if(rotationState == defaultRotation) { // default -> rotation4
        rotationState = rotation4;
        // do the math to properly rotate in in the cartiasian cordinates
        //NOTE: THE AXIS DOES NOT CHANGE FOR L!
        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);
        // LL

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 1);
        // L
        // LL

        blocks[3].setX(x + 0);
        blocks[3].setY(y - 2);
        // L
        // L
        // LL

    } else if (rotationState == rotation2) { // rotation2 -> default
        rotationState = defaultRotation;
        // NOTE: THE AXIS DOES NOT CHANGE FOR L
        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);
        // L
        // L

        blocks[2].setX(x + 1);
        blocks[2].setY(y - 1);
        // LL
        // L

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);
        // LLL
        // L
    } else if (rotationState == rotation3) { // rotation3 -> rotation2
        rotationState = rotation2;
        // NOTE: THE HEAD WILL SHIFT OVER BY X + 1
        x += 1;
        blocks[0].setX(x);
        // y does not change
        //
        //
        //  L

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);
        //
        //  L
        //  L

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 2);
        //  L
        //  L
        //  L

        blocks[3].setX(x - 1);
        blocks[3].setY(y - 2);
        // LL
        //  L
        //  L

    } else if (rotationState == rotation4) { // rotation 4 -> rotation2
        rotationState = rotation3;
        // NOTE: THE HEAD MUST CHANGE BACK
        x -= 1;
        blocks[0].setX(x);
        //
        // L

        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);
        //   
        // LL

        blocks[1].setX(x + 2);
        blocks[1].setY(y + 0);
        //   
        // LLL

        blocks[1].setX(x + 2);
        blocks[1].setY(y - 1);
        //   L
        // LLL
    }
    return std::make_unique<L>(newShape);
}
