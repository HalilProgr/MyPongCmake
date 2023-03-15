#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_circle_shape.h"
#include "box2d/b2_fixture.h"

class Circle {

	//Math algorithm simulate
	b2World* _world;
	b2Body*  b2_circle;

	//Visulation SFML
	sf::Vector2u _sizeWindow;

	sf::Color _outlineColor = sf::Color::Black;
	sf::Color _filColor = sf::Color(100, 100, 200);
	float _radius = 10;
	float _thickness = 3;
	sf::CircleShape _circle;

	
public:
	Circle(b2World* world, sf::Vector2u sizeWindow);

	void update();
	
	const b2Vec2&  getPosition();
	//void setSpeed(float speed);

	//float getSpeed() const;

	operator sf::CircleShape()const;
};