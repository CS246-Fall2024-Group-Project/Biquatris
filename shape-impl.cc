#include <block.h>
#include <shape.h>
#include <vector>
#include <memory>

using namespace std;

// the third rowfrom the top, bottom parts of shapes will start at 2 and build upwards towards the top of the screen
// Each shape will work in a "3x3" grid
int TOP_OF_SCREEN = 2;
int MIDDLE_OF_SCREEN = 6;

Shape::Shape(char letter) : letter{letter}, rotationState(1) {}

Shape::Shape(const Shape& other)
    : letter(other.letter),
      rotationState(other.rotationState),
      blocks(other.blocks) {}

char Shape::getLetter() const {
    return letter;
}

// move shape left
std::unique_ptr<Shape> Shape::left() {
    auto newShape = std::make_unique<Shape>(*this);
    for(auto & block: newShape->blocks) {
        block.setX(block.getX() - 1);
    }
    return newShape;
}

// move shape right
std::unique_ptr<Shape> Shape::right() {
    auto newShape = std::make_unique<Shape>(*this);
    for(auto & block: newShape->blocks) {
        block.setX(block.getX() + 1);
    }
    return newShape;
}

// Move shape down
std::unique_ptr<Shape> Shape::down() {
    auto newShape = std::make_unique<Shape>(*this);
    for(auto & block: newShape->blocks) {
        block.setY(block.getY() - 1);
    }
    return newShape;
}

// ctor
L::L(int startX, int startY): Shape('L') {
    // this is de default L rotation state
    Block head = {startX - 1, startY, letter};
    // 
    // L

    Block c2 = {startX, startY, letter};
    //
    // LL

    Block c3 = {startX + 1, startY, letter};
    // 
    // LLL

    Block c4 = {startX + 1, startY - 1, letter};
    //   L
    // LLL
    blocks.emplace_back(head);
    blocks.emplace_back(c2);
    blocks.emplace_back(c3);
    blocks.emplace_back(c4);
}

// L copy ctor
L::L(const L&other) : Shape(other) {}

// L clockwise
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

        blocks[2].setX(x + 2);
        blocks[2].setY(y + 0);

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);

    }
    return std::make_unique<L>(newShape);
}

// L counter-clockwise
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
        //             LL
        //   L ----->   L
        // LLL          L
        x += 1;
        blocks[0].setX(x);

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);
        // LL

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 2);

        blocks[3].setX(x - 1);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation2) { // rotation2 -> default
        rotationState = defaultRotation;
        // NOTE: THE AXIS DOES NOT CHANGE FOR L
        // L
        // L  -------->    L
        // LL            LLL
        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);

        blocks[2].setX(x + 2);
        blocks[2].setY(y + 0);

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);
    } else if (rotationState == rotation3) { // rotation3 -> rotation2
        rotationState = rotation2;
        //                    L
        // LLL  ------------> L
        // L                  LL

        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 1);

        blocks[3].setX(x + 0);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation4) { // rotation4 -> rotation3
        rotationState = rotation3;
        // LL
        //  L --------> LLL
        //  L           L

        x -= 1;
        blocks[0].setX(x);

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x + 1);
        blocks[2].setY(y - 1);

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);
    }

    return std::make_unique<L>(newShape);
}

// J ctor
J::J(int startX, int startY): Shape('J') {
    // default rotation state for J
    // J
    // JJJ

    Block head = {startX - 1, startY, letter};
    //
    // J

    Block c2 = {startX - 1, startY - 1, letter};
    // J
    // J

    Block c3 = {startX, startY, letter};
    // J
    // JJ

    Block c4 = {startX + 1, startY, letter};
    // J
    // JJJ

    blocks.emplace_back(head);
    blocks.emplace_back(c2);
    blocks.emplace_back(c3);
    blocks.emplace_back(c4);
}

// J copy ctor
J::J(const J&other) : Shape(other) {}

// J clockwise
std::unique_ptr<Shape> J::clockwise() {
    // axis of rotation does not change!

    int x = blocks.front().getX(); // get the x-axis of the axis
    int y = blocks.front().getY(); // get the y-axis of the axis

    J newShape(*this);
    
    // do not change
    int defaultRotation = 1;
    // *
    // ***

    int rotation2 = 2;
    // **
    // *
    // *

    int rotation3 = 3;
    // ***
    //   *

    int rotation4 = 4;
    //  *
    //  *
    // **

    if(rotationState == defaultRotation) { // default -> rotation2
        rotationState = rotation2;
        //            JJ
        // J   -----> J
        // JJJ        J
        
        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 2);

        blocks[3].setX(x + 1);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation2) { // rotation2 -> rotation3
        rotationState = rotation3;
        // JJ
        // J  ------> JJJ
        // J            J

        // NEED TO MOVE THE HAD TO THE RIGHT
        x += 2;
        blocks[0].setX(x);

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x - 1);
        blocks[2].setY(y - 1);

        blocks[3].setY(x - 2);
        blocks[3].setY(y - 1);
        
    } else if (rotationState == rotation3) { // rotation3 -> rotation4
        rotationState = rotation4;
        //               J
        // JJJ ------->  J
        //   J          JJ

        // need to move the head to the lower left
        x -= 2;
        blocks[0].setX(x);

        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);

        blocks[2].setX(x + 1);
        blocks[2].setY(y - 1);

        blocks[3].setX(x + 1);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation4) { // rotation 4 -> defaultRotation
        rotationState = defaultRotation;
        //  J
        //  J  -------->  J
        // JJ             JJJ

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x + 1);
        blocks[2].setY(y - 1);

        blocks[3].setX(x + 2);
        blocks[3].setY(y - 1);

    }
    return std::make_unique<L>(newShape);
}

// J counter-clockwise
std::unique_ptr<Shape> J::counter() {
    // axis of rotation does not change!

    int x = blocks.front().getX(); // get the x-axis of the axis
    int y = blocks.front().getY(); // get the y-axis of the axis

    J newShape(*this);
    
    // do not change
    int defaultRotation = 1;
    // *
    // ***

    int rotation2 = 2;
    // **
    // *
    // *

    int rotation3 = 3;
    // ***
    //   *

    int rotation4 = 4;
    //  *
    //  *
    // **

    if(rotationState == defaultRotation) { // default -> rotation4
        rotationState = rotation2;
        //            J
        // J   -----> J
        // JJJ        JJ
        
        blocks[1].setX(x + 1);
        blocks[1].setY(y + 0);

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 1);

        blocks[3].setX(x + 0);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation2) { // rotation2 -> default
        rotationState = rotation3;
        // JJ
        // J  ------> J
        // J          JJJ

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x - 1);
        blocks[2].setY(y - 1);

        blocks[3].setY(x - 2);
        blocks[3].setY(y - 1);
        
    } else if (rotationState == rotation3) { // rotation3 -> rotation2
        rotationState = rotation4;
        //              JJ
        // JJJ -------> J
        //   J          J

        // need to move the head to the lower left
        x -= 2;
        blocks[0].setX(x);

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x + 0);
        blocks[2].setY(y - 2);

        blocks[3].setX(x + 1);
        blocks[3].setY(y - 2);

    } else if (rotationState == rotation4) { // rotation 4 -> rotation3
        rotationState = defaultRotation;
        // xJ
        // xJ  -------->  JJJ
        // JJ             xxJ

        x += 2;

        blocks[1].setX(x + 0);
        blocks[1].setY(y - 1);

        blocks[2].setX(x - 1);
        blocks[2].setY(y - 1);

        blocks[3].setX(x - 2);
        blocks[3].setY(y - 1);

    }
    return std::make_unique<L>(newShape);
}

// O ctor
O::O(int startX, int startY)
