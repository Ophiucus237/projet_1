#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Platform {
public:
    Platform();
    void add(float x, float y, float width, float height, sf::Color color);
    void draw(sf::RenderWindow& window);
    std::vector<sf::FloatRect> getCollisions() const; // Renvoie les zones de collision

private:
    std::vector<sf::RectangleShape> rectangles;
};