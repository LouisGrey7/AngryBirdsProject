//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Object.cpp
// Description	: Object class for blocks in the scene
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#include "Object.h"
#include "iostream"

//Initialises an object in the scene
Object::Object(sf::Vector2f _position, float _scale, b2BodyType _bodytype, std::string _spritename, b2World* _world)
{
	//Set sprite
	m_texture.loadFromFile("Resources/Sprites/" + _spritename);
	m_sprite.setTexture(m_texture);
	float originX = (m_texture.getSize().x / 2.0f);
	float originY = (m_texture.getSize().y / 2.0f);
	m_sprite.setOrigin(originX, originY);


	//Box 2D setup
	m_bodyDef.position = b2Vec2(_position.x / _scale, _position.y / _scale);
	m_bodyDef.type = _bodytype;
	m_body = _world->CreateBody(&m_bodyDef);


	m_shape.SetAsBox(originX  / _scale, originY  / _scale);
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.restitution = 0.5f;
	m_fixtureDef.shape = &m_shape;
	m_body->CreateFixture(&m_fixtureDef);


	m_body->GetUserData().pointer = (uintptr_t)this;
}

Object::~Object()
{
	if (m_body != nullptr)
	{
		m_body->GetWorld()->DestroyBody(m_body);
	}
	m_body = nullptr;
}

//Renders an object
void Object::Render(sf::RenderWindow& _window, float _scale)
{
	m_sprite.setPosition(m_body->GetPosition().x * _scale, m_body->GetPosition().y * _scale);
	m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	_window.draw(m_sprite);
}

//FOR DEBUGGING PURPOSES/Overrides with contact listener
void Object::StartContact(Object* other)
{

	//std::cout << "hit\n" << std::endl;
}
void Object::EndContact(Object* other)
{
	//std::cout << "end hit\n" << std::endl;

}
