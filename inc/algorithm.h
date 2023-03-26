#pragma once

#include "circle.h"
#include "paddle.h"
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"

class Algoritm {

	float SCALE = 10;

	//main system coordinat
	// 
	// 
	//Math algorithm simulate
	b2World* _world;

	Circle _circle;
	Paddle _leftPaddle;
	Paddle _rightPaddle;

	sf::RenderWindow& _window;
	sf::Vector2u sizeWindow = _window.getSize();


	const float tCorSystem = _window.getSize().y;

	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(0.1f);
	const float paddleSpeed = 400.f;
	float rightPaddleSpeed = 0.f;
	const float ballSpeed = 400.f;

	void restartGame();

	void setWall(int x, int y, int w, int h);

public:
	Algoritm(sf::RenderWindow& window, b2World* world);

	void update();

};