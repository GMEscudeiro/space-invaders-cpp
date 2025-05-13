#include "Bullet.hpp"

Bullet::Bullet(const sf::Vector2f& position, float speed)
    : speed(speed) {
    shape.setSize({5.f, 15.f});
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void Bullet::update(sf::Time deltaTime) {
    shape.move(0.f, speed * deltaTime.asSeconds());
}

void Bullet::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool Bullet::isOffScreen(float windowHeight) const {
    return shape.getPosition().y > windowHeight;
}

sf::FloatRect Bullet::getBounds() const {
    return shape.getGlobalBounds();
}

