#ifndef GAMESCREEN_H
#define GAMESCREEN_H


#include "start.h"
#include "Screen.h"
#include "Snake.h"


// -------------------------------
// Section: Game Screen
// -------------------------------



static sf::Vector2f generateRandomPosition(float width, float height) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, WINDOW_WIDTH - width);
    std::uniform_int_distribution<> disY(0, WINDOW_HEIGHT - height);
    return sf::Vector2f(disX(gen), disY(gen));
}
class Game;

class GameScreen : public Screen {
public:
    GameScreen(Game& gameInstance);

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;

private:
    Snake snake_;
    std::vector<Shape> shapes_;
    Direction currentDirection_;
    sf::Clock clock_;
    Shape food_;
    int foodEaten_;
    Game& game_;
};

#endif
