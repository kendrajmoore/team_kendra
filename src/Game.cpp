#include "start.h"
#include "Game.h"
#include "MenuScreen.h"


// -------------------------------
// Section: Game Class Instance
// -------------------------------


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game()
        : window_(sf::VideoMode(Game::Width, Game::Height), "Snake Game"),
          currentScreen_(std::make_shared<MenuScreen>(*this)) {

}

void Game::handleInput(){
    sf::Event event;
    while(window_.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window_.close();
        }
        currentScreen_->handleInput(window_);
    }
}

void Game::update(sf::Time delta){
    currentScreen_->update(delta);
}

void Game::render(){
    window_.clear();
    currentScreen_->render(window_);
    window_.display();
}

void Game::run(){
    window_.setFramerateLimit(60);
    window_.setVerticalSyncEnabled(true);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(window_.isOpen()){
        sf::Time delta = clock.restart();
        timeSinceLastUpdate += delta;
        while(timeSinceLastUpdate > Game::TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            handleInput();
            update(TimePerFrame);
        }
        render();
    }
}
