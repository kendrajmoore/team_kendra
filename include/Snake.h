#ifndef SNAKE_H
#define SNAKE_H

#include "start.h"


// -------------------------------
// Section: Snake
// -------------------------------


class Snake{
public:
    Snake();
    void move();
    void checkCollisions(Shape& food, int& foodEaten);
    void grow();
    void setDirection(Direction newDirection);
    void render(sf::RenderWindow& window);
    bool isGameOver() const;
    sf::Vector2f getHeadPosition() const;

private:
    Direction currentDirection_;
    std::vector<Shape> shapes_;
    bool isGameOver_;
};

#endif