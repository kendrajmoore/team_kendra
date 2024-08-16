#include "start.h"
#include "Snake.h"
#include "Game.h"
#include "GameScreen.h"

// -------------------------------
// Section: Snake
// -------------------------------


Snake::Snake(): currentDirection_(None), isGameOver_(false){
    sf::Vector2f startPosition(Game::Width / 2 - SQUARE_SIZE / 2, Game::Height / 2 - SQUARE_SIZE / 2);
    shapes_.emplace_back(SQUARE_SIZE, SQUARE_SIZE, startPosition, sf::Color::Green);
    for (int i = 1; i < 3; ++i) {
        startPosition.x -= SQUARE_SIZE;
        shapes_.emplace_back(SQUARE_SIZE, SQUARE_SIZE, startPosition, sf::Color::Green);
    }
}
void Snake::setDirection(Direction newDirection){
    currentDirection_ = newDirection;
}


void Snake::render(sf::RenderWindow& window){
    for (auto& shape : shapes_)
        shape.draw(window);
}

void Snake::move(){
    for (int i = shapes_.size() - 1; i > 0; --i) {
        shapes_[i].shape.setPosition(shapes_[i - 1].getPosition());
    }

    shapes_[0].move(currentDirection_, SQUARE_SIZE);
}

void Snake::checkCollisions(Shape& food, int& foodEaten){
    if (shapes_[0].getBounds().intersects(food.getBounds())) {
        grow();
        foodEaten++;
        food.shape.setFillColor(sf::Color::Red);
        sf::sleep(sf::milliseconds(100));
        food.shape.setPosition(generateRandomPosition(SQUARE_SIZE, SQUARE_SIZE));
        food.shape.setFillColor(sf::Color::Magenta);
    }

    if (currentDirection_ != None) {
        for (int i = 1; i < shapes_.size(); ++i) {
            if (shapes_[0].getBounds().intersects(shapes_[i].getBounds())) {
                isGameOver_ = true;
                break;
            }
        }
    }

}

void Snake::grow() {
    for (int i = 0; i < 5; ++i) {
        sf::Vector2f lastSegmentPosition = shapes_.back().getPosition();
        if (currentDirection_ == Left)
            lastSegmentPosition.x += SQUARE_SIZE;
        else if (currentDirection_ == Right)
            lastSegmentPosition.x -= SQUARE_SIZE;
        else if (currentDirection_ == Up)
            lastSegmentPosition.y += SQUARE_SIZE;
        else if (currentDirection_ == Down)
            lastSegmentPosition.y -= SQUARE_SIZE;
        Shape newSegment(SQUARE_SIZE, SQUARE_SIZE, lastSegmentPosition, sf::Color::Green);
        shapes_.push_back(newSegment);
    }
}

bool Snake::isGameOver() const {
    return isGameOver_;
}