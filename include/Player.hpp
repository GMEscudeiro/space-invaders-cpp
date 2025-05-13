#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Bullet.hpp"
class Player {
public:
    Player(const sf::Vector2u& windowSize); // Constructor to initialize player

    void handleInput();                   // Handle player input
    void update(sf::Time deltaTime);      // Update player state
    void draw(sf::RenderWindow& window);  // Draw player on screen
    void shoot();
    void updateBullets(sf::Time deltaTime, sf::Vector2u windowSize); // Update bullets
    void drawBullets(sf::RenderWindow& window) const;
    const std::vector<Bullet>& getBullets() const; // Get bullets for collision detection

    // Getter for player bounds (for collision)
    sf::FloatRect getBounds() const;

    // Optional: set/reset position
    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape;             // Visual representation
    float speed;                          // Movement speed
    sf::Vector2u windowSize;
    std::vector<Bullet> bullets; // Store bullets
    sf::Clock shootTimer; // Clock to manage bullet timing
    float shootCooldown = 0.3f; // Cooldown time in seconds
};

