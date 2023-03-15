#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

class Paddle {
	//box2d
	b2World* _world;
	b2Body* b2_Box;

	float _speed = 0;

	//SFML
	sf::Vector2u _sizeWindow;
	sf::Vector2f _position;

	float _thickness = 3;
	sf::Color _outlineColor = sf::Color::Black;
	sf::Color _filColor = sf::Color(100, 100, 200);
	sf::RectangleShape  _rectangle;
	sf::Vector2f		size = sf::Vector2f(20,100);

	//float _speed = 0;

public:
	Paddle(b2World* world, sf::Vector2u sizeWindow, sf::Vector2f position);

	void setSpeed(float speed);
	//void setPosition(float x, float y);
	

	//float getSpeed() const;

	void update();

	operator sf::RectangleShape()const;
};