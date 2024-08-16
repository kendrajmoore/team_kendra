#include "start.h"
#include "Game.h"
#include "GameScreen.h"
#include "GameWonScreen.h"
#include "GameLostScreen.h"


// -------------------------------
// Section: Game Screen Instance
// -------------------------------

GameScreen::GameScreen(Game& gameInstance)
    :
    game_(gameInstance),
    currentDirection_(None),
    foodEaten_(0),
    food_() {

    sf::Vector2f startPosition(WINDOW_WIDTH / 2 - SQUARE_SIZE / 2, WINDOW_HEIGHT / 2 - SQUARE_SIZE / 2);
    shapes_.emplace_back(SQUARE_SIZE, SQUARE_SIZE, startPosition, sf::Color::Green);
}

void GameScreen::handleInput(sf::RenderWindow& window) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && currentDirection_ != Right)
        currentDirection_ = Left;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && currentDirection_ != Left)
        currentDirection_ = Right;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && currentDirection_ != Down)
        currentDirection_ = Up;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && currentDirection_ != Up)
        currentDirection_ = Down;;

    snake_.setDirection(currentDirection_);
}


void GameScreen::update(sf::Time delta) {
    if (clock_.getElapsedTime().asSeconds() >= MOVE_DELAY) {
        clock_.restart();
        snake_.move();
        snake_.checkCollisions(food_, foodEaten_, game_);
    }

}


void GameScreen::render(sf::RenderWindow& window) {
    window.clear();
    snake_.render(window);
    food_.draw(window);
    window.display();
}



