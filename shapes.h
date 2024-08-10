#ifndef TEAM_KENDRA_SHAPES_H
#define TEAM_KENDRA_SHAPES_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <vector>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define SQUARE_SIZE 20.f

struct Shape {
    sf::RectangleShape shape;
    Shape(float width, float height, sf::Vector2f position, sf::Color color) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(position);
        shape.setFillColor(color);
    }
    void draw(sf::RenderWindow& window){
        window.draw(shape);
    }
};

#endif //TEAM_KENDRA_SHAPES_H
