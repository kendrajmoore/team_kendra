#include "GameWonScreen.h"
#include "GameScreen.h"
#include "ScreenUtils.h"

// -------------------------------
// Section: Game Won Screen
// -------------------------------



GameWonScreen::GameWonScreen(Game& gameInstance)
        : game_(gameInstance){
    setupText(text_, font_, "You Win! Press Enter to return to the Menu", 24, sf::Color::White, 400, 400);

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