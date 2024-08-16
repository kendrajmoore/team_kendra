#include "start.h"
#include "Snake.h"
#include "Game.h"
#include "GameWonScreen.h"
#include "GameLostScreen.h"


// -------------------------------
// Section: Snake
// -------------------------------

Game game;
Snake::Snake(): currentDirection_(None), isGameOver_(false){
    sf::Vector2f startPosition(Game::Width / 2 - SQUARE_SIZE / 2, Game::Height / 2 - SQUARE_SIZE / 2);
    shapes_.emplace_back(SQUARE_SIZE, SQUARE_SIZE, startPosition, sf::Color::Red);
    for (int i = 1; i < 3; ++i) {
        startPosition.x -= SQUARE_SIZE;
        shapes_.emplace_back(SQUARE_SIZE, SQUARE_SIZE, startPosition, sf::Color::Green);
    }
}

sf::Vector2f Snake::getHeadPosition() const {
    return shapes_.front().getPosition();
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
        shapes_[i].shape.setFillColor(sf::Color::Green);
    }

    shapes_[0].move(currentDirection_, SQUARE_SIZE);
    shapes_[0].shape.setFillColor(sf::Color::Red);
}

void Snake::checkCollisions(Food& food, int& foodEaten, Game& game){
    if (shapes_[0].getBounds().intersects(food.getBounds())) {
        grow();
        foodEaten++;

        food.setFillColor(sf::Color::Red);
        sf::sleep(sf::milliseconds(100));

        bool validPosition = false;
        while(!validPosition){
            food.respawn();
            food.setFillColor(sf::Color::Magenta);
            validPosition = true;
            for (const auto& segment : shapes_) {
                if (food.getBounds().intersects(segment.getBounds())) {
                    validPosition = false;
                    break;
                }
            }
        }
        if (foodEaten >= MAX_FOOD_COUNT) {
            game.currentScreen_ = std::make_shared<GameWonScreen>(game);
            return;
        }

    }

    sf::Vector2f headPosition = getHeadPosition();
    if (headPosition.x < 0 || headPosition.x >= WINDOW_WIDTH || headPosition.y < 0 || headPosition.y >= WINDOW_HEIGHT) {
        game.currentScreen_ = std::make_shared<GameLostScreen>(game);
        return;
    }


    if (currentDirection_ != None) {
        for (int i = 1; i < shapes_.size(); ++i) {
            if (shapes_[0].getBounds().intersects(shapes_[i].getBounds())) {
                game.currentScreen_ = std::make_shared<GameLostScreen>(game);
                return;
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
