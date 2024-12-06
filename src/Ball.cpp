#include "Ball.h"

Ball::Ball() : velocity(5.0f, 5.0f) {
    ball.setRadius(10.0f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(400, 300);
}

void Ball::update() {
    ball.move(velocity);
    if (ball.getPosition().y < 0 || ball.getPosition().y > 590) {
        velocity.y = -velocity.y;
    }
}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(ball);
}

void Ball::accelerate() {
    velocity.x *= 1.1f;
    velocity.y *= 1.1f;
}

void Ball::reset() {
    ball.setPosition(400, 300);
    velocity = {5.0f, 5.0f};
}

sf::Vector2f Ball::getPosition() const {
    return ball.getPosition();
}

bool Ball::checkCollision(const sf::RectangleShape &paddle) {
    return ball.getGlobalBounds().intersects(paddle.getGlobalBounds());
}
