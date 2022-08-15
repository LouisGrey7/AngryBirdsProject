#include "Bird.h"

Bird::Bird()
{
	int randSprite = rand() % 6;


	switch (randSprite)
	{
	case 0:
		m_texture.loadFromFile("Resources/Sprites/Goon1.png");
		break;
	case 1:
		m_texture.loadFromFile("Resources/Sprites/Goon2.png");
		break;
	case 2:
		m_texture.loadFromFile("Resources/Sprites/Goon3.png");
		break;
	case 3:
		m_texture.loadFromFile("Resources/Sprites/Goon4.png");
		break;
	case 4:
		m_texture.loadFromFile("Resources/Sprites/Goon5.png");
		break;
	case 5:
		m_texture.loadFromFile("Resources/Sprites/Goon6.png");
		break;

	}

	//Set sprite
	m_sprite.setTexture(m_texture);
	float originX = (m_texture.getSize().x / 2);
	float originY = (m_texture.getSize().y / 2);
	m_sprite.setOrigin(originX, originY);

}

void Bird::Launch(float _scale, sf::Vector2f _position, b2World& _world)
{

	// Box2d set up

	m_bodyDef.position = b2Vec2(_position.x / _scale, _position.y / _scale);

	m_bodyDef.type = b2_dynamicBody;

	m_body = _world.CreateBody(&m_bodyDef);



	float originX = (m_texture.getSize().x / 2);

	m_shape.m_radius = (originX) / _scale;

	m_fixtureDef.density = 5.0f;

	m_fixtureDef.shape = &m_shape;

	m_body->CreateFixture(&m_fixtureDef);

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
