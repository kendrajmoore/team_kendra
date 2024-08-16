#ifndef FOOD_H
#define FOOD_H

#include "start.h"
#include <SFML/Graphics.hpp>

// -------------------------
// Section: Food Class
// -------------------------

class Food : public Shape {
public:
    Food();

    void respawn();

};

#endif