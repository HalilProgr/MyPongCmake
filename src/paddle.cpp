#include "paddle.h"


Paddle::Paddle(b2World* world, sf::Vector2u sizeWindow, sf::Vector2f position):
	_world(world), _position(position), _sizeWindow(sizeWindow)
{

	b2PolygonShape pl;
	pl.SetAsBox(size.x/2, size.y/2);

	b2FixtureDef paddleFix;
	paddleFix.restitution = 1.0f;
	paddleFix.density = 1.0f;
	paddleFix.shape = &pl;

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(_position.x, _position.y);
	bd.linearDamping = 0.0f;
	bd.angularDamping = 0.0f;

	b2_Box = _world->CreateBody(&bd);
	b2_Box->CreateFixture(&paddleFix);

	//SFML
	_rectangle.setSize(size - sf::Vector2f(_thickness, _thickness));
	_rectangle.setOutlineThickness(_thickness);
	_rectangle.setOutlineColor(_outlineColor);
	_rectangle.setFillColor(_filColor);
	_rectangle.setOrigin(size / 2.f);
	_rectangle.setPosition(_position);
}


void Paddle::update() {
	float x = b2_Box->GetPosition().x;
	float y = b2_Box->GetPosition().y;
	std::cout << _sizeWindow.y << std::endl;


	_rectangle.setPosition(x, _sizeWindow.y - y);
}

void Paddle::setSpeed(float speed) {
	if (_speed != speed) {
		b2_Box->SetLinearVelocity(b2Vec2(0,speed));
		_speed = speed;
	}
}

Paddle::operator sf::RectangleShape() const
{
	return _rectangle;
}

