#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2u& windowSize); // Constructor to initialize player

    void handleInput();                   // Handle player input
    void update(sf::Time deltaTime);      // Update player state
    void draw(sf::RenderWindow& window);  // Draw player on screen

    // Getter for player bounds (for collision)
    sf::FloatRect getBounds() const;

    // Optional: set/reset position
    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;
    sf::Vector2u windowSize;

private:
    sf::RectangleShape shape;             // Visual representation
    float speed;                          // Movement speed
    // Add more private members as needed (e.g., texture, health)
};

