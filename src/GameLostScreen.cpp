#include "GameLostScreen.h"
#include "GameScreen.h"
#include "Game.h"
#include "ScreenUtils.h"

// -------------------------------
// Section: Game Lost Screen
// -------------------------------



GameLostScreen::GameLostScreen(Game& gameInstance)
        : game_(gameInstance) {
    setupText(text_, font_, "Game Over! Press Enter to return to the Menu", 24, sf::Color::White, 400, 400);
}

void GameLostScreen::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        game_.currentScreen_ = std::make_shared<GameScreen>(game_);
    }
}

void GameLostScreen::update(sf::Time delta) {}

void GameLostScreen::render(sf::RenderWindow& window) {
    window.clear();;
    window.draw(text_);
    window.display();
}
