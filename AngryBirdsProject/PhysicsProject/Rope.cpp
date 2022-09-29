//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Rope.cpp
// Description	: Creates a rope of circle objects
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
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

	DJD.length = 0.1f;
	DJD.stiffness = 20.0f;
	DJD.damping = 0.1f;

	DJD2.length = 0.1f;
	DJD2.stiffness = 15.0f;
	DJD2.damping = 0.1f;

	DJD3.length = 0.1f;
	DJD3.stiffness = 15.0f;
	DJD3.damping = 0.1f;

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