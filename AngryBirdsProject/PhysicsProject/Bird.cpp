//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Bird.cpp
// Description	: Functionality for Bird class
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#include "Bird.h"

//Creates a bird based on the given type. Loads image from file
Bird::Bird(BIRDTYPE _BirdType)
{
	m_body = 0;
	switch (_BirdType)
	{
	case BIRDTYPE::REDBIRD:
		m_texture.loadFromFile("Resources/Sprites/RedBird.png");
		m_birdtype = BIRDTYPE::REDBIRD;
		break;

	case BIRDTYPE::YELLOWBIRD:
		m_texture.loadFromFile("Resources/Sprites/YellowBird.png");
		m_birdtype = BIRDTYPE::YELLOWBIRD;
		break;

	case BIRDTYPE::GREENBIRD:
		m_texture.loadFromFile("Resources/Sprites/GreenBird.png");
		m_birdtype = BIRDTYPE::GREENBIRD;
		break;

	case BIRDTYPE::BLUEBIRD:
		m_texture.loadFromFile("Resources/Sprites/BlueBird.png");
		m_birdtype = BIRDTYPE::BLUEBIRD; 
		break;

	default:
		m_texture.loadFromFile("Resources/Sprites/RedBird.png");
		m_birdtype = BIRDTYPE::REDBIRD;
		break;
	}

	//Set sprite
	m_sprite.setTexture(m_texture);
	float originX = (m_texture.getSize().x / 2.0f);
	float originY = (m_texture.getSize().y / 2.0f);
	m_sprite.setOrigin(originX, originY);


}
Bird::~Bird()
{
	//m_body->DestroyFixture(m_body->GetFixtureList());
	if (m_body != nullptr)
	{
		m_body->GetWorld()->DestroyBody(m_body);
	}
	m_body = nullptr;
}

//When the mouse is released, bird is flung into the world!
void Bird::Launch(float _scale, sf::Vector2f _position, b2World& _world)
{
	// Box2d set up
	m_bodyDef.position = b2Vec2(_position.x / _scale, _position.y / _scale);
	m_bodyDef.type = b2_dynamicBody;
	m_body = _world.CreateBody(&m_bodyDef);

	float originX = (m_texture.getSize().x / 2.0f);
	m_shape.m_radius = (originX) / _scale;

	m_fixtureDef.density = 5.0f;
	m_fixtureDef.shape = &m_shape;
	m_body->CreateFixture(&m_fixtureDef);

	m_Launched = true;
}

//Draw bird sprite on screen
void Bird::Render(sf::RenderWindow& _window, float _scale)
{
	if (m_body != nullptr)
	{
		m_sprite.setPosition(m_body->GetPosition().x * _scale, m_body->GetPosition().y * _scale);
		m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	}

	_window.draw(m_sprite);
}

//Each bird (except red) has a unique special ability, triggered here. (Called from level.cpp after hitting a certain point).
void Bird::UseSpecialAbility(float _scale)
{
	if (!m_AbilityActivated)
	{
		switch (this->m_birdtype)
		{
		case BIRDTYPE::YELLOWBIRD: //Special ability go zoom zoom
			this->m_body->ApplyLinearImpulse(b2Vec2(this->m_body->GetLinearVelocity().x * (_scale), this->m_body->GetLinearVelocity().y * (_scale))
													, this->m_body->GetPosition(), true);
			break;
		case BIRDTYPE::GREENBIRD: //The boomerang bird. No-U turn around.
			this->m_body->ApplyAngularImpulse(1.0f, true);
			this->m_body->SetLinearVelocity(b2Vec2(0.0f, this->m_body->GetLinearVelocity().y));
			this->m_body->ApplyLinearImpulse(b2Vec2(-400.0f, 500.0f), this->m_body->GetPosition(), true);
			break;
		case BIRDTYPE::BLUEBIRD:
			break;
		}
	}
	m_AbilityActivated = false; //Makes sure the ability only triggers once per bird.
}
