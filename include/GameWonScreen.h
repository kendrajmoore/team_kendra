#ifndef GAMEWONSCREEN_H
#define GAMEWONSCREEN_H

#include "start.h"
#include "Screen.h"
#include "Game.h"

// -------------------------------
// Section: Game Won Screen
// -------------------------------



class GameWonScreen : public Screen {
public:
    GameWonScreen(Game& gameInstance);

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text text_;
    sf::Font font_;
    Game& game_;
};

#endif
