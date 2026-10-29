#pragma once
#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera(sf::RenderWindow& window);
    void follow(sf::Vector2f target, float deltaTime);
    void apply(sf::RenderWindow& window);

private:
    sf::View view;
    float followSpeed; // Pour une caméra fluide
};