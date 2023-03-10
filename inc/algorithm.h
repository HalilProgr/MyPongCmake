#pragma once

#include "circle.h"
#include "paddle.h"
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"

class Algoritm {
	float const PI = std::acos(-1);

	//Math algorithm simulate
	b2World* world;
	b2Body* upBound;
	b2Body* dwBound;
	b2Body* lfBound;
	b2Body* rgBound;

	Paddle &_leftPaddle;
	Paddle &_rightPaddle;
	Circle &_circle;

	sf::RenderWindow &_window;

	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(0.1f);
	const float paddleSpeed = 400.f;
	float rightPaddleSpeed = 0.f;
	const float ballSpeed = 400.f;

	void restartGame();

public:
	Algoritm(sf::RenderWindow& window,
		Paddle& leftPaddle,
		Paddle& rightPaddle,
		Circle& circle);

	void update(float delta, sf::Time Aitime);

};