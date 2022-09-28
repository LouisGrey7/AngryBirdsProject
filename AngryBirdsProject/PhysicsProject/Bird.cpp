#include "Bird.h"

Bird::Bird(int _BirdType)
{
	m_body = 0;
	switch (_BirdType)
	{
	case 0:
		m_texture.loadFromFile("Resources/Sprites/RedBird.png");
		m_birdtype = BIRDTYPE::REDBIRD;
		break;
	case 1:
		m_texture.loadFromFile("Resources/Sprites/YellowBird.png");
		m_birdtype = BIRDTYPE::YELLOWBIRD;
		break;
	case 2:
		m_texture.loadFromFile("Resources/Sprites/GreenBird.png");
		m_birdtype = BIRDTYPE::GREENBIRD;
		break;
	case 3:
		m_texture.loadFromFile("Resources/Sprites/BlueBird.png");
		m_birdtype = BIRDTYPE::BLUEBIRD; 
		break;
	case 4:
		m_texture.loadFromFile("Resources/Sprites/Goon5.png");
		m_birdtype = BIRDTYPE::REDBIRD;//PLACEHOLDER
		break;
	case 5:
		m_texture.loadFromFile("Resources/Sprites/Goon6.png");
		m_birdtype = BIRDTYPE::REDBIRD;//PLACEHOLDER
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
	m_body->DestroyFixture(m_body->GetFixtureList());
	m_body = nullptr;
}

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

void Bird::Render(sf::RenderWindow& _window, float _scale)
{
	if (m_body != nullptr)
	{
		m_sprite.setPosition(m_body->GetPosition().x * _scale, m_body->GetPosition().y * _scale);
		m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	}

	_window.draw(m_sprite);
}

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
			this->m_body->ApplyLinearImpulse(b2Vec2(-400.0f, 250.0f), this->m_body->GetPosition(), true);
			break;
		case BIRDTYPE::BLUEBIRD:
			//new Bird(BIRDTYPE::BLUEBIRD, this->GetBody()->GetPosition().x, this->GetBody()->GetPosition().y + 50);
			break;
		}
	}
	m_AbilityActivated = false;
}
