#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Cube - SFML");
    window.setFramerateLimit(60);

    sf::RectangleShape cube(sf::Vector2f(100.f, 100.f));
    cube.setFillColor(sf::Color::Blue);
    cube.setOutlineThickness(3.f);
    cube.setOutlineColor(sf::Color::Black);
    cube.setPosition({350.f, 250.f});

    float speed = 250.f;       // vitesse horizontale
    float velocity = 0.f;      // vitesse verticale (chute/saut)
    float jumpForce = -600.f;  // force du saut (négatif = monte)
    float gravity = 1500.f;    // gravité (positif = descend)
    bool onGround = true;      // le cube est-il au sol ?

    sf::Clock horloge;

    while (window.isOpen()) {
        float deltaTime = horloge.restart().asSeconds();

        // Récupère la position AVANT les modifications
        sf::Vector2f position = cube.getPosition();

        // --- Événements ---
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // --- Gravité (appliquée à chaque frame) ---
        velocity += gravity * deltaTime;
        position.y += velocity * deltaTime;

        // --- Déplacement horizontal ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            position.x -= speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            position.x += speed * deltaTime;
        }

        // --- Saut avec Espace ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && onGround) {
            velocity = jumpForce;
            onGround = false;
        }

        // --- Détection du sol ---
        if (position.y >= 500.f) {
            position.y = 500.f;
            velocity = 0.f;
            onGround = true;
        }

        // Applique la nouvelle position
        cube.setPosition(position);

        // --- Rendu ---
        window.clear(sf::Color::Black);
        window.draw(cube);
        window.display();
    }

    return 0;
}