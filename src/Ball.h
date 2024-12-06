#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape ball;
    sf::Vector2f velocity;

public:
    Ball();
    void update();
    void draw(sf::RenderWindow &window);
    void accelerate();
    void reset();
    sf::Vector2f getPosition() const;
    bool checkCollision(const sf::RectangleShape &paddle);
};
