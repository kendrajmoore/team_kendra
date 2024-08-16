#ifndef SCREEN_H
#define SCREEN_H

#include "start.h"

// -------------------------------
// Section: Screen
// -------------------------------


class Screen {
public:
    virtual ~Screen() = default;
    virtual void handleInput(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif