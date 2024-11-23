#ifndef SHAPE_H
#define SHAPE_H

#include <block.h>
#include <vector>
#include <memory>

class Shape {
    protected:
        char letter;
        int rotationState;
        std::vector<Block> blocks;

    public:
        Shape(char letter);
        Shape(const Shape& other);
        virtual ~Shape() = default;
        virtual std::unique_ptr<Shape> clockwise() = 0;
        virtual std::unique_ptr<Shape> counter() = 0;
        std::unique_ptr<Shape> left();
        std::unique_ptr<Shape> right();
        std::unique_ptr<Shape> down();

        char getLetter() const;
        std::vector<Block> getBlocks() const;
        virtual ~Shape() = default;
};

class L : public Shape {
    public:
        L(int startX, int startY/*, int turn*/);
        L(const L& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class J : public Shape {
    public:
        J(int startX, int startY/*, int turn*/);
        J(const J& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class I : public Shape {
    public:
        I(int startx, int startY/*, int turn*/);
        I(const I& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class O : public Shape {
    public:
        O(int startx, int startY/*, int turn*/);
        O(const O& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class Z : public Shape {
    public:
        Z(int startx, int startY/*, int turn*/);
        Z(const Z& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class S : public Shape {
    public:
        S(int startx, int startY/*, int turn*/);
        S(const S& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};

class T : public Shape {
    public:
        T(int startx, int startY/*, int turn*/);
        T(const T& other);
        std::unique_ptr<Shape> clockwise() override;
        std::unique_ptr<Shape> counter() override;
};
#endif
