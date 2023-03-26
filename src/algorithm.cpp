#include "algorithm.h"

Algoritm::Algoritm(sf::RenderWindow& window, b2World* world) :
    _window(window), _world(world), _circle(world, window.getSize()),
    _leftPaddle(world, window.getSize(), sf::Vector2f(40+10,300)),
    _rightPaddle(world, window.getSize(), sf::Vector2f(800 - 40 - 10, 300))

{
    //setWall(-5, sizeWindow.y/2, 5, sizeWindow.y / 2);
    //setWall(sizeWindow.x + 5, sizeWindow.y / 2, 5, sizeWindow.y / 2);
    setWall(sizeWindow.x/2, -5, sizeWindow.x/2, 5);
    setWall(sizeWindow.x/2, sizeWindow.y + 5, sizeWindow.x/2, 5);
}

void Algoritm::update()
{
    //Gamer Paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _leftPaddle.setSpeed(500);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _leftPaddle.setSpeed(-500);
    }
    else {
        _leftPaddle.setSpeed(0);
    }

    //AI right Paddle
    if (_rightPaddle.getPosition().y > _circle.getPosition().y)
    {
        _rightPaddle.setSpeed(-500);
    }
    else if (_rightPaddle.getPosition().y < _circle.getPosition().y)
    {
        _rightPaddle.setSpeed(500);
    }
    else {
        _rightPaddle.setSpeed(0);
    }

    // restart game

    if (_circle.getPosition().x < 0 || _circle.getPosition().x > _window.getSize().x)
        restartGame();



    _circle.update();
    _leftPaddle.update();
    _rightPaddle.update();

    _window.clear();
    _window.draw(_leftPaddle);
    _window.draw(_rightPaddle);
    _window.draw(_circle);
    _window.display();
}

void Algoritm::restartGame()
{
    _leftPaddle.setPosition(sf::Vector2f(40 + 10, 300));
    _rightPaddle.setPosition(sf::Vector2f(800 - 40 - 10, 300));
    _circle.setPosition(sf::Vector2f(_window.getSize().x/2, _window.getSize().y/2));
    _circle.setSpeed(b2Vec2(400, 300));
}

void Algoritm::setWall(int x, int y, int w, int h)
{
    b2PolygonShape gr;
    gr.SetAsBox(w/SCALE, h/SCALE);

    b2BodyDef bdef;
    bdef.position.Set(x/SCALE, y/SCALE);

    b2Body* b_ground = _world->CreateBody(&bdef);
    b_ground->CreateFixture(&gr, 0.0f);
}