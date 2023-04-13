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
    std::unique_ptr<b2World> world = std::make_unique<b2World>(b2Vec2(0.0f, 0.0f));

    sf::RenderWindow window(sf::VideoMode(sizeWindow.x, sizeWindow.y), "My Pong");
    window.setVerticalSyncEnabled(true);

    bool isPlaying = false;
    

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Halil\\Desktop\\VSproject\\game\\MyPongCmake\\res\\sansation.ttf"))
        return EXIT_FAILURE;

    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(100.f, 150.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to SFML and Box2d pong!\nPress space to start the game");
    
    window.draw(pauseMessage);
    window.display();

    Algoritm algoritm(window, &(*world));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) {
                if (!isPlaying) {
                    isPlaying = !isPlaying;
                }
            }
        }



        if (isPlaying) {
            world->Step(1.0f / 60.0f, 6, 4);
            algoritm.update();
        }
    }

    return 0;
}