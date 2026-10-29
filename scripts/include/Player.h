#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
public:
    Player();
    void handleEvents(const sf::Event& event);
    void update(float deltaTime, const std::vector<sf::FloatRect>& collisions);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape cube;
    float speed;
    float velocity;
    float jumpForce;
    float gravity;
    bool onGround;
    bool jumpKeyHeld;
    bool wantToJump;
};