#include "Paddle.h"

Paddle::Paddle(bool isPlayer1)
    : isPlayer1(isPlayer1) {
    paddle.setSize(sf::Vector2f(25, 100));
    paddle.setFillColor(sf::Color::White);
    if (isPlayer1) {
        paddle.setPosition(50, 250);
    } else {
        paddle.setPosition(725, 250);
    }
}

void Paddle::update() {
    if (isPlayer1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle.getPosition().y > 0) {
            paddle.move(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddle.getPosition().y < 500) {
            paddle.move(0, 5);
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle.getPosition().y > 0) {
            paddle.move(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle.getPosition().y < 500) {
            paddle.move(0, 5);
        }
    }
}

void Paddle::draw(sf::RenderWindow &window) {
    window.draw(paddle);
}

void Paddle::reset() {
    if (isPlayer1) {
        paddle.setPosition(50, 250);
    } else {
        paddle.setPosition(725, 250);
    }
}

sf::RectangleShape& Paddle::getShape() {
    return paddle;
}