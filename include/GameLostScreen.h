#ifndef GAMELOSTSCREEN_H
#define GAMELOSTSCREEN_H

#include "start.h"
#include "Screen.h"
#include "Game.h"


// -------------------------
// Section: Game Lost Screen
// -------------------------


class GameLostScreen : public Screen{
public:
    GameLostScreen(Game& gameInstance);

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text text_;
    sf::Font font_;
    Game& game_;
};



#endif