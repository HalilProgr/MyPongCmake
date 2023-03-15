#include <SFML/Graphics.hpp>

#include "paddle.h"
#include "circle.h"
#include "algorithm.h"
#include <iostream>

#include "box2d/b2_math.h"
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

int main()
{

    sf::Vector2f sizeWindow(800, 600);
    sf::Vector2f paddleSize(25, 100);

    //b2box main object
    b2World* world = new b2World(b2Vec2(0.0f, 0.0f));

    sf::RenderWindow window(sf::VideoMode(sizeWindow.x, sizeWindow.y), "My Pong");
    window.setVerticalSyncEnabled(true);
    /*
    Paddle leftPaddle(paddleSize, 3, sf::Color(100, 100, 200), sf::Color::Black);
    leftPaddle.setSpeed(400.f);
    leftPaddle.setPosition(10 + paddleSize.x / 2, sizeWindow.y / 2);

    Paddle rightPaddle(paddleSize, 3, sf::Color(100, 100, 200), sf::Color::Black);
    rightPaddle.setSpeed(400.f);
    rightPaddle.setPosition(sizeWindow.x - 10 - paddleSize.x / 2, sizeWindow.y / 2);

    Circle ball(10, 3, sf::Color::White, sf::Color::Green);
    ball.setPosition(sizeWindow.x / 2, sizeWindow.y / 2);
    ball.setSpeed(-200);
    */
    sf::Clock clock;
    bool isPlaying = false;

    /*
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\lea-k\\Desktop\\Visual code\\game\\myPongCmake\\res\\sansation.ttf"))
        return EXIT_FAILURE;

    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");
    */

    Algoritm algoritm(window, world);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }


        float delta = clock.restart().asSeconds();


        // algorithm.update(AItime, delta)
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            leftPaddle.move(-delta);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            leftPaddle.move(delta);
        }

        ball.move(delta);
        */

        world->Step(delta, 6, 4);

        algoritm.update();
    }
    return 0;
}