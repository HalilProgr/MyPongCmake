#include "algorithm.h"

Algoritm::Algoritm(sf::RenderWindow& window, b2World* world) :
    _window(window), _world(world), _circle(world, window.getSize()),
    _leftPaddle(world, window.getSize(), sf::Vector2f(40+10,300)),
    _rightPaddle(world, window.getSize(), sf::Vector2f(800 - 40 - 10, 300))

{
    setWall(-5, sizeWindow.y/2, 5, sizeWindow.y / 2);
    setWall(sizeWindow.x + 5, sizeWindow.y / 2, 5, sizeWindow.y / 2);
    setWall(sizeWindow.x/2, -5, sizeWindow.x/2, 5);
    setWall(sizeWindow.x/2, sizeWindow.y + 5, sizeWindow.x/2, 5);
}

void Algoritm::update()
{
    //Gamer Paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _leftPaddle.setSpeed(1000);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _leftPaddle.setSpeed(-1000);
    }
    else {
        _leftPaddle.setSpeed(0);
    }

    //AI right Paddle
    if (_rightPaddle.getPosition().y > _circle.getPosition().y)
    {
        _rightPaddle.setSpeed(-1000);
    }
    else if (_rightPaddle.getPosition().y < _circle.getPosition().y)
    {
        _rightPaddle.setSpeed(1000);
    }
    else {
        _rightPaddle.setSpeed(0);
    }

    _circle.update();
    _leftPaddle.update();
    _rightPaddle.update();

    _window.clear();
    _window.draw(_leftPaddle);
    _window.draw(_rightPaddle);
    _window.draw(_circle);
    _window.display();
}

void Algoritm::setWall(int x, int y, int w, int h)
{
    b2PolygonShape gr;
    gr.SetAsBox(w, h);

    b2BodyDef bdef;
    bdef.position.Set(x, y);

    b2Body* b_ground = _world->CreateBody(&bdef);
    b_ground->CreateFixture(&gr, 0.0f);
}