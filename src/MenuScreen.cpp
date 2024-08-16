
#include "MenuScreen.h"
#include "GameScreen.h"
#include "ScreenUtils.h"

// -------------------------------
// Section: Menu Screen
// -------------------------------



class Game;

MenuScreen::MenuScreen(Game& gameInstance) : game_(gameInstance) {
    setupText(text_, font_, "Press Enter to Start", 24, sf::Color::White, 400, 400);;
}

void MenuScreen::handleInput(sf::RenderWindow& window){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        game_.currentScreen_ = std::make_shared<GameScreen>(game_);
    }
}

void MenuScreen::update(sf::Time delta) {}

void MenuScreen::render(sf::RenderWindow& window){
    window.clear();
    window.draw(text_);
    window.display();
}