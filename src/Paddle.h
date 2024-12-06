#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape paddle;
    bool isPlayer1;

public:
    Paddle(bool isPlayer1);
    void update();
    void draw(sf::RenderWindow &window);
    void reset();
    sf::RectangleShape& getShape();
};
