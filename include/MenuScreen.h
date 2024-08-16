#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "start.h"
#include "Screen.h"
#include "Game.h"

// -------------------------------
// Section: Menu Screen
// -------------------------------


class Game;

class MenuScreen : public Screen {
public:
    MenuScreen(Game& gameInstance);
    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text text_;
    sf::Font font_;
    Game& game_;
};
#endif