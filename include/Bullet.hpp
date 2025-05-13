#pragma once

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(const sf::Vector2f& position, float speed = -500.f);

    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window) const;
    bool isOffScreen(float windowHeight) const;

    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    float speed;
};

