//
// Created by Kendra Moore on 8/15/24.
//

#ifndef TEAM_KENDRA_START_H
#define TEAM_KENDRA_START_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <memory>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define SQUARE_SIZE 20.f
#define MOVE_DELAY 0.2f
#define MAX_FOOD_COUNT 100



// -------------------------------
// Section: Snake Game
// -------------------------------



enum Direction { None, Left, Right, Up, Down };

struct Shape {
    sf::RectangleShape shape;
    Shape(float width, float height, sf::Vector2f position, sf::Color color) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(position);
        shape.setFillColor(color);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    void move(Direction dir, float speed) {
        sf::Vector2f offset(0.f, 0.f);
        if (dir == Left) {
            offset.x = -speed;
        } else if (dir == Right) {
            offset.x = speed;
        } else if (dir == Up) {
            offset.y = -speed;
        } else if (dir == Down) {
            offset.y = speed;
        }

        shape.move(offset);
    }
    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }

};

#endif //TEAM_KENDRA_START_H
