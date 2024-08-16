#ifndef GAME_H
#define GAME_H

#include "start.h"
#include "Screen.h"


// -------------------------
// Section: Game Class
// -------------------------

class Game {
public:
    Game();
    void run();
    static const unsigned Width = WINDOW_WIDTH;
    static const unsigned Height = WINDOW_HEIGHT;
    std::shared_ptr<Screen> currentScreen_;

private:
    void handleInput();
    void update(sf::Time delta);
    void render();

    sf::RenderWindow window_;
    static const sf::Time TimePerFrame;

};

#endif



