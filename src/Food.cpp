
#include "Food.h"
#include "GameScreen.h"

// -------------------------
// Section: Food Class
// -------------------------

Food::Food()
    :Shape(SQUARE_SIZE, SQUARE_SIZE, generateRandomPosition(SQUARE_SIZE, SQUARE_SIZE), sf::Color::Magenta) {}

void Food::respawn() {
    setPosition(generateRandomPosition(SQUARE_SIZE, SQUARE_SIZE));
}

