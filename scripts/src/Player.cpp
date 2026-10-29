#include "../include/Player.h"

Player::Player() : cube(sf::Vector2f(50.f, 50.f)), jumpKeyHeld(false), wantToJump(false) {
    cube.setFillColor(sf::Color::Blue);
    cube.setOutlineThickness(3.f);
    cube.setOutlineColor(sf::Color::Black);
    cube.setPosition({250.f, 50.f});

    speed = 400.f;
    velocity = 0.f;
    jumpForce = -850.f;
    gravity = 1500.f;
    onGround = false;
}

void Player::handleEvents(const sf::Event& event) {
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Space) {
            if (!jumpKeyHeld) {
                wantToJump = true;
                jumpKeyHeld = true;
            }
        }
    }
    if (const auto* keyReleased = event.getIf<sf::Event::KeyReleased>()) {
        if (keyReleased->code == sf::Keyboard::Key::Space) {
            jumpKeyHeld = false;
        }
    }
}

void Player::update(float deltaTime, const std::vector<sf::FloatRect>& collisions) {
    sf::Vector2f position = cube.getPosition();
    
    // --- 1. SAUT ---
    if (wantToJump && onGround) {
        velocity = jumpForce;
        onGround = false;
        wantToJump = false; 
    }

    // --- 2. DEPLACEMENT HORIZONTAL ---
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) position.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) position.x += speed * deltaTime;

    // --- 3. GRAVITE ET MOUVEMENT VERTICAL ---
    if (!onGround) {
        velocity += gravity * deltaTime;
    }
    position.y += velocity * deltaTime;

    // On applique la position temporaire
    cube.setPosition(position);

    // --- 4. COLLISIONS (Le vrai secret est ici) ---
    bool isGrounded = false;
    sf::FloatRect playerBounds = cube.getGlobalBounds();

    // On sauvegarde l'ancienne position Y pour savoir d'où on vient
    float previousY = cube.getPosition().y - velocity * deltaTime;

    for (const auto& platform : collisions) {
        // Si le cube touche une plateforme
        if (playerBounds.findIntersection(platform)) {
            
            // On vérifie si on descend (velocity > 0) ET si on vient d'au-dessus de la plateforme
            // Le "+ 5.f" est une petite marge de tolérance
            if (velocity > 0.f && previousY + playerBounds.size.y <= platform.position.y + 5.f) {
                
                // On pose le cube PILE sur le dessus de la plateforme
                float exactY = platform.position.y - playerBounds.size.y;
                cube.setPosition({position.x, exactY});
                
                velocity = 0.f; 
                isGrounded = true;
                break; // On a trouvé notre sol, on arrête de vérifier
            }
        }
    }

    // --- 5. TOLERANCE ANTI-TREMBLEMENT ---
    // Si on n'a pas détecté de collision exacte, on vérifie si on est à 2 pixels du sol
    // Cela empêche la gravité de faire trembler le cube quand il est posé.
    if (!isGrounded) {
        sf::FloatRect feetCheck = cube.getGlobalBounds();
        feetCheck.position.y += 2.f; // On regarde 2 pixels plus bas
        for (const auto& platform : collisions) {
            if (feetCheck.findIntersection(platform)) {
                // On vérifie qu'on est bien au-dessus (pas collé sur le côté)
                if (cube.getPosition().y + playerBounds.size.y <= platform.position.y + 4.f) {
                    isGrounded = true;
                    velocity = 0.f; 
                    break;
                }
            }
        }
    }

    onGround = isGrounded;

    // Si on a appuyé sur espace en l'air, on annule la demande
    if (!onGround && wantToJump) {
        wantToJump = false;
    }

    // --- 6. REAPPARITION ---
    if (cube.getPosition().y > 1000.f) {
        cube.setPosition({250.f, 50.f});
        velocity = 0.f;
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(cube);
}

sf::Vector2f Player::getPosition() const {
    return cube.getPosition();
}