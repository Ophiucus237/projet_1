#include "Camera.h"

Camera::Camera(sf::RenderWindow& window) {
    // On initialise la vue avec la taille de la fenêtre
    view = sf::View(sf::FloatRect({0.f, 0.f}, {600.f, 400.f}));
    followSpeed = 5.f; // La caméra rattrape le joueur en douceur
}

void Camera::follow(sf::Vector2f target, float deltaTime) {
    // On calcule le centre de l'écran par rapport au joueur
    sf::Vector2f currentCenter = view.getCenter();
    
    // Interpolation linéaire (Lerp) pour un mouvement fluide
    float newX = currentCenter.x + (target.x - currentCenter.x) * followSpeed * deltaTime;
    float newY = currentCenter.y + (target.y - currentCenter.y) * followSpeed * deltaTime;
    
    view.setCenter({newX, newY});
}

void Camera::apply(sf::RenderWindow& window) {
    window.setView(view);
}