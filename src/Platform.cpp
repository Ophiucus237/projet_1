#include "../include/Platform.h"

Platform::Platform() {
    // 1. La longue plateforme bleue de base (le sol)
    add(-1000.f, 400.f, 3000.f, 100.f, sf::Color::Blue);
    
    // 2. Des plateformes flottantes pour tester les sauts
    add(200.f, 250.f, 150.f, 30.f, sf::Color::Cyan);
    add(500.f, 100.f, 200.f, 30.f, sf::Color::Cyan);
    add(-300.f, 200.f, 150.f, 30.f, sf::Color::Cyan);
}

void Platform::add(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition({x, y});
    rect.setFillColor(color);
    rect.setOutlineThickness(2.f);
    rect.setOutlineColor(sf::Color::Black);
    rectangles.push_back(rect);
}

void Platform::draw(sf::RenderWindow& window) {
    for (auto& rect : rectangles) {
        window.draw(rect);
    }
}

std::vector<sf::FloatRect> Platform::getCollisions() const {
    std::vector<sf::FloatRect> bounds;
    for (const auto& rect : rectangles) {
        bounds.push_back(rect.getGlobalBounds());
    }
    return bounds;
}