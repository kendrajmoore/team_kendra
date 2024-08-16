#include "start.h"
#include "GameLostScreen.h"
#include "GameScreen.h"
#include "Game.h"

// -------------------------------
// Section: Game Lost Screen
// -------------------------------



GameLostScreen::GameLostScreen(Game& gameInstance)
        : game_(gameInstance) {
    font_.loadFromFile("Orbitron-Black.ttf");
    text_.setFont(font_);
    text_.setString("Game Over! Press Enter");
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::White);
    text_.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text_.getLocalBounds();
    text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text_.setPosition(400, 400);
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
