#include "paddle.h"


Paddle::Paddle(b2World* world, sf::Vector2u sizeWindow, sf::Vector2f position):
	_world(world), _position(position), _sizeWindow(sizeWindow)
{

	b2PolygonShape pl;
	pl.SetAsBox(size.x/(2*SCALE), size.y/(2*SCALE));

	b2FixtureDef paddleFix;
	paddleFix.restitution = 0.0f;
	paddleFix.density = 1.0f;
	paddleFix.shape = &pl;

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(_position.x/SCALE, _position.y/SCALE);
	bd.linearDamping = 0.0f;
	bd.angularDamping = 0.0f;
	bd.fixedRotation = true;

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


const b2Vec2& Paddle::getPosition()
{
	return b2_Box->GetPosition();
}

void Paddle::update() {
	float x = b2_Box->GetPosition().x*SCALE;
	float y = b2_Box->GetPosition().y*SCALE;


	_rectangle.setPosition(x, _sizeWindow.y - y);
}

void Paddle::setSpeed(float speed) {
	if (_speed != speed) {
		b2_Box->SetLinearVelocity(b2Vec2(0,speed));
		_speed = speed;
	}
}

void Paddle::setPosition(sf::Vector2f pos)
{
	b2_Box->SetTransform(b2Vec2(pos.x / SCALE, pos.y / SCALE), 0);
}

Paddle::operator sf::RectangleShape() const
{
	return _rectangle;
}

