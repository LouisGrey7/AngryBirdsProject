#include "Rope.h"
Rope::Rope(float x, float y, b2World* world)
{





	box1 = (new Object(sf::Vector2f(x, y), 30.0f, b2BodyType::b2_staticBody, "Net.png", world));
	box2 = (new Object(sf::Vector2f(x, y+25), 30.0f, b2BodyType::b2_dynamicBody, "Net.png", world));
	box3 = (new Object(sf::Vector2f(x, y+50), 30.0f, b2BodyType::b2_dynamicBody, "Net.png", world));
	box4 = (new Object(sf::Vector2f(x, y+550), 30.0f, b2BodyType::b2_staticBody, "Net.png", world));



	DJD.bodyA = box1->GetBody();
	DJD.bodyB = box2->GetBody();
	
	DJD2.bodyA = box2->GetBody();
	DJD2.bodyB = box3->GetBody();


	DJD3.bodyA = box3->GetBody();
	DJD3.bodyB = box4->GetBody();

	DJD.length = 0.1;
	DJD.stiffness = 20;
	DJD.damping = 0.1;

	DJD2.length = 0.1;
	DJD2.stiffness = 15;
	DJD2.damping = 0.1;

	DJD3.length = 0.1;
	DJD3.stiffness = 15;
	DJD3.damping = 0.1;

	joint = (b2DistanceJoint*)world->CreateJoint(&DJD);
	joint2 = (b2DistanceJoint*)world->CreateJoint(&DJD2);
	joint3 = (b2DistanceJoint*)world->CreateJoint(&DJD3);
}

Rope::~Rope()
{


}


void Rope::Render(sf::RenderWindow& _window, float _scale)
{
	box1->m_sprite.setPosition(box1->m_body->GetPosition().x * _scale, box1->m_body->GetPosition().y * _scale);
	box1->m_sprite.setRotation(box1->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(box1->m_sprite);

	box2->m_sprite.setPosition(box2->m_body->GetPosition().x * _scale, box2->m_body->GetPosition().y * _scale);
	box2->m_sprite.setRotation(box2->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(box2->m_sprite);


	box3->m_sprite.setPosition(box3->m_body->GetPosition().x * _scale, box3->m_body->GetPosition().y * _scale);
	box3->m_sprite.setRotation(box3->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(box3->m_sprite);

	box4->m_sprite.setPosition(box4->m_body->GetPosition().x * _scale, box4->m_body->GetPosition().y * _scale);
	box4->m_sprite.setRotation(box4->m_body->GetAngle() * 180 / b2_pi);
	_window.draw(box4->m_sprite);
}