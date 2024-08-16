#ifndef SCREEN_UTILS_H
#define SCREEN_UTILS_H

#include <SFML/Graphics.hpp>

inline void setupText(sf::Text& text, sf::Font& font, const std::string& string, unsigned int size, sf::Color color, float posX, float posY) {
    font.loadFromFile("../assets/Orbitron-Black.ttf");
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(posX, posY);
}

#endif
