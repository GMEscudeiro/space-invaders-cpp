#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>

Player::Player(const sf::Vector2u& windowSize) : windowSize(windowSize) {
    // Initialize the player shape, position, speed, etc.
    shape.setSize(sf::Vector2f(50.f, 50.f)); // Example size
    shape.setFillColor(sf::Color::Green);     // Example color
    speed = 300.f;                           // Example speed
    shape.setPosition(375.f, 550.f);          // Initial position near the bottom-center
}

void Player::handleInput() {
    // Handle player movement based on key input (left, right)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape.move(-speed * 0.016f, 0.f); // Move left (scaled by delta time)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape.move(speed * 0.016f, 0.f); // Move right (scaled by delta time)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shoot(); // Call shoot function when space is pressed
    }
}

void Player::update(sf::Time deltaTime) {
    // Update player state (can be extended with jumping, shooting, etc.)
    // For now, we'll move based on input
  handleInput();
  sf::Vector2f position = shape.getPosition();
  if(position.x < 0) {
      position.x = 0;
  } else if(position.x + shape.getSize().x > windowSize.x) { // Assuming window width is 800
      position.x = windowSize.x - shape.getSize().x;
  }

  shape.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) {
    // Draw the player shape to the screen
    window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
    // Return the bounding box for collision detection
    return shape.getGlobalBounds();
}

void Player::setPosition(const sf::Vector2f& pos) {
    // Set player position
    shape.setPosition(pos);
}

sf::Vector2f Player::getPosition() const {
    // Get player position
    return shape.getPosition();
}

void Player::shoot() {
  if(shootTimer.getElapsedTime().asSeconds() >= shootCooldown) {
      sf::Vector2f bulletPos(shape.getPosition().x + shape.getSize().x / 2 - 2.5f, shape.getPosition().y); // Center the bullet
    bullets.emplace_back(bulletPos); // Create a new bullet
    shootTimer.restart();
  }
}

void Player::updateBullets(sf::Time deltaTime, sf::Vector2u windowSize) {
  for(auto& bullet : bullets) {
    bullet.update(deltaTime);
  }
  bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [windowSize](const Bullet& bullet) {
    return bullet.isOffScreen(windowSize.y);
  }), bullets.end());
}

void Player::drawBullets(sf::RenderWindow& window) const {
  for(const auto& bullet : bullets) {
    bullet.draw(window);
  }
}

const std::vector<Bullet>& Player::getBullets() const {
  return bullets;
}
