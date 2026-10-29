#include <SFML/Graphics.hpp>
#include <optional>
#include "Player.h"
#include "Platform.h"
#include "Camera.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Prototype - Platforms & Camera");
    window.setFramerateLimit(60);

    // Initialisation des modules
    Player player;
    Platform level;
    Camera camera(window);

    sf::Clock clock;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        // 1. Gestion des événements
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            // On transmet l'événement au joueur pour qu'il puisse sauter
            player.handleEvents(*event);
        }

        // 2. Mise à jour de la physique
        // On passe les zones de collision des plateformes au joueur
        player.update(deltaTime, level.getCollisions());

        // 3. Mise à jour de la caméra
        camera.follow(player.getPosition(), deltaTime);

        // 4. Rendu graphique
        window.clear(sf::Color(50, 50, 50)); // Gris foncé
        
        camera.apply(window); // On applique la vue avant de dessiner
        level.draw(window);
        player.draw(window);
        
        window.display();
    }

    return 0;
}