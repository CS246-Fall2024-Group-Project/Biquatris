#ifndef SHAPE_H
#define SHAPE_H

#include <block.h>
#include <vector>

class Shape {
    protected:
        char letter;
        std::vector<Block> blocks;

    public:
    virtual ~Shape() = default;
        virtual void clockwise() = 0;
        virtual void counter() = 0;
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void down() = 0;

        char getLetter() const;
};

class L : public Shape {
    public:
        L(int startX, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;

};

class J : public Shape {
    public:
        J(int startX, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};

class I : public Shape {
    public:
        I(int startx, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};

class O : public Shape {
    public:
        O(int startx, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};

class Z : public Shape {
    public:
        Z(int startx, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};

class S : public Shape {
    public:
        S(int startx, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};

class T : public Shape {
    public:
        T(int startx, int startY);
        void clockwise() override;
        void counter() override;

        void left() override;
        void right() override;
        void down() override;
};
#endif
