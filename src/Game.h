#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

class Game {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;

    // Игровые объекты
    Paddle player1, player2;
    Ball ball;

    // Счет
    int score1, score2;
    int maxScore;

    void processEvents();
    void update();
    void render();
    void resetRound();

public:
    Game();
    void run();
};
