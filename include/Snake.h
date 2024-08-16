#ifndef SNAKE_H
#define SNAKE_H

#include "Food.h"
#include "Game.h"


// -------------------------------
// Section: Snake
// -------------------------------


class Snake{
public:
    Snake();
    void move();
    void checkCollisions(Food& food, int& foodEaten, Game& game);
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