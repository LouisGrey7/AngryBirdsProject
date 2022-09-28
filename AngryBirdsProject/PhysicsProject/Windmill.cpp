#include "Windmill.h"

Windmill::Windmill(float x, float y, b2World* world)
{
	boxV = (new Object(sf::Vector2f(x, y), 30.0f, b2BodyType::b2_staticBody, "Block.png", world));
	boxH = (new Object(sf::Vector2f(x, y), 30.0f, b2BodyType::b2_dynamicBody, "BlockH.png", world));



	RJD.Initialize(boxV->m_body, boxH->m_body, boxV->m_body->GetWorldCenter());
	RJD.motorSpeed = 3.14 * 2;
	RJD.maxMotorTorque = 1000.0;
	RJD.enableMotor = true;

	joint = (b2RevoluteJoint*)world->CreateJoint(&RJD);
}

Windmill::~Windmill()
{
	delete boxV;
	delete boxH;

}


void Windmill::Render(sf::RenderWindow& _window, float _scale)
{
	boxV->m_sprite.setPosition(boxV->m_body->GetPosition().x * _scale, boxV->m_body->GetPosition().y * _scale);
	boxV->m_sprite.setRotation(boxV->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(boxV->m_sprite);

	boxH->m_sprite.setPosition(boxH->m_body->GetPosition().x * _scale, boxH->m_body->GetPosition().y * _scale);
	boxH->m_sprite.setRotation(boxH->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(boxH->m_sprite);
}