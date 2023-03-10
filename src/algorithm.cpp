#include "algorithm.h"

Algoritm::Algoritm(sf::RenderWindow& window, Paddle& leftPaddle,
					   Paddle& rightPaddle,  Circle& circle):
    _window(window), _circle(circle), _leftPaddle(leftPaddle), _rightPaddle(rightPaddle)
{
    world = new b2World(b2Vec2(0.0f, 0.0f));
    b2BodyDef groundBodyDef;
    b2PolygonShape groundBox;
    groundBox.SetAsBox(800.0f, 10.0f);
    groundBodyDef.position.Set(0.0f, -305.0f);

    dwBound = world->CreateBody(&groundBodyDef);
    dwBound->CreateFixture(&groundBox, 0.0f);

    groundBodyDef.position.Set(0.0f, 305.0f);
    upBound = world->CreateBody(&groundBodyDef);
    upBound->CreateFixture(&groundBox, 0.0f);

    groundBox.SetAsBox(10.0f, 800.0f);
    groundBodyDef.position.Set(-405.0f, 0.0f);
    lfBound = world->CreateBody(&groundBodyDef);
    lfBound->CreateFixture(&groundBox, 0.0f);

    groundBodyDef.position.Set(405.0f, 0.0f);
    rgBound = world->CreateBody(&groundBodyDef);
    rgBound->CreateFixture(&groundBox, 0.0f);

}

void Algoritm::update(float delta, sf::Time Aitime)
{



}
