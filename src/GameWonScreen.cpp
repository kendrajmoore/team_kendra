#include "start.h"
#include "GameWonScreen.h"
#include "GameScreen.h"

// -------------------------------
// Section: Game Won Screen
// -------------------------------



GameWonScreen::GameWonScreen(Game& gameInstance)
        : game_(gameInstance){
    font_.loadFromFile("Orbitron-Black.ttf");
    text_.setFont(font_);
    text_.setString("You Win! Press Enter to return to the Menu");
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::White);
    text_.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text_.getLocalBounds();
    text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text_.setPosition(400, 400);
}

void GameWonScreen::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        game_.currentScreen_ = std::make_shared<GameScreen>(game_);
    }
}

void GameWonScreen::update(sf::Time delta) {}

void GameWonScreen::render(sf::RenderWindow& window){
    window.draw(text_);
}