#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong Game"), 
      player1(true), player2(false),
      ball(), score1(0), score2(0), maxScore(10) {
    // Загружаем шрифт для отображения счета
    if (!font.loadFromFile("assets/fonts/Arial.ttf")) {
        std::cerr << "Error loading font\n";
        // Если шрифт не найден, можно завершить программу
        exit(1);
    }

    // Инициализация текста счета
    scoreText.setFont(font);             // Устанавливаем шрифт
    scoreText.setCharacterSize(24);      // Размер текста
    scoreText.setFillColor(sf::Color::White);  // Белый цвет текста
    scoreText.setPosition(350, 10);      // Позиция текста на экране
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    ball.update();

    // Проверка на столкновения с ракетками
    if (ball.checkCollision(player1.getShape()) || ball.checkCollision(player2.getShape())) {
        ball.accelerate();
    }

    // Обновление счета
    if (ball.getPosition().x < 0) {
        score2++;
        resetRound();
    } else if (ball.getPosition().x > 800) {
        score1++;
        resetRound();
    }
}

void Game::render() {
    window.clear();  // Очистка экрана
    player1.draw(window);  // Рисуем ракетку игрока 1
    player2.draw(window);  // Рисуем ракетку игрока 2
    ball.draw(window);     // Рисуем мяч

    // Отображение счета
    std::stringstream ss;
    ss << score1 << " : " << score2;  // Формируем строку с текущим счетом
    scoreText.setString(ss.str());    // Устанавливаем текст
    window.draw(scoreText);           // Рисуем текст на экране

    window.display();  // Отображаем все объекты на экране
}

void Game::resetRound() {
    ball.reset();
    player1.reset();
    player2.reset();
}