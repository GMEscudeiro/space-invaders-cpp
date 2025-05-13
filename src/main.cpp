#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Space Invaders";

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time delta);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;

    // Game objects will go here, e.g.:
    // std::vector<Enemy> enemies;
    Player player;
};

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
      player(window.getSize())
{
    window.setFramerateLimit(60);
}

void Game::run() {
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processEvents();
        update(delta);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Handle key input (can be moved to player later)
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }
    }
}

void Game::update(sf::Time delta) {
  player.update(delta);
  player.updateBullets(delta, window.getSize());
}

void Game::render() {
    window.clear();

    player.draw(window);
    player.drawBullets(window);

    window.display();
}

int main() {
    try {
        Game game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;

}
