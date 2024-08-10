#include <string>
#include <iostream>
#include <random>
#include "shapes.h"


void createSquares(std::vector<Shape>& shapes) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, WINDOW_WIDTH - 20);
    std::uniform_int_distribution<> disY(0, WINDOW_HEIGHT - 20);

    sf::Vector2f pinkPosition(disX(gen), disY(gen));
    shapes.emplace_back(20.f, 20.f, pinkPosition, sf::Color::Magenta);

    sf::Vector2f bluePosition(disX(gen), disY(gen));
    shapes.emplace_back(20.f, 20.f, bluePosition, sf::Color::Green);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake");
    std::vector<Shape> shapes;
    createSquares(shapes);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for(auto& shape: shapes){
            shape.draw(window);
        }
        window.display();
    }


    return 0;
}