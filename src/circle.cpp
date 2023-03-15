#include "circle.h"

Circle::Circle(b2World* world, sf::Vector2u sizeWindow):
	_world(world), _sizeWindow(sizeWindow)
{

	// create visualisation 
	_circle.setRadius(_radius - _thickness);
	_circle.setOutlineThickness(_thickness);
	_circle.setOutlineColor(_outlineColor);
	_circle.setFillColor(_filColor);
	_circle.setOrigin(sf::Vector2f(_radius, _radius) / 2.f);

	{
		b2CircleShape shape;
		shape.m_radius = _radius;

		b2FixtureDef ballFixtureDef;
		ballFixtureDef.restitution = 1.0f;
		ballFixtureDef.density = 0.001;
		ballFixtureDef.shape = &shape;

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.linearDamping = 0.0f;
		bd.angularDamping = 0.0f;
		bd.position.Set(_sizeWindow.x/2, _sizeWindow.y/2);

		b2_circle = _world->CreateBody(&bd);
		b2_circle->CreateFixture(&ballFixtureDef);
		b2_circle->ApplyLinearImpulseToCenter(b2Vec2(5000,0),true);
	}
}

void Circle::update()
{
	//std::cout <<"X: "<< b2_circle->GetPosition().x << " Y: " << b2_circle->GetPosition().y << std::endl;
	float x = (b2_circle->GetPosition().x);
	float y = (_sizeWindow.y - b2_circle->GetPosition().y);
	_circle.setPosition(x, y);
}
const b2Vec2&  Circle::getPosition()
{
	return b2_circle->GetPosition();
}
/*
void Circle::setSpeed(float speed)
{
	//_speed = speed;
}

void Circle::setPosition(float x, float y)
{
	//_circle.move
}
*/

Circle::operator sf::CircleShape() const
{
	return _circle;
}


