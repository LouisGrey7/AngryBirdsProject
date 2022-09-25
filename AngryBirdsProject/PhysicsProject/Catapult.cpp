#include "Catapult.h"

Catapult::Catapult(sf::Vector2f _position)
{
	//Set sprite
	m_texture.loadFromFile("Resources/Sprites/Catapult.png");
	m_sprite.setTexture(m_texture);
	float originX = (m_texture.getSize().x / 2.0f);
	float originY = (m_texture.getSize().y / 2.0f);
	m_sprite.setOrigin(originX, originY);

	m_sprite.setPosition(_position);

	m_firingOrigin = _position;
	m_firingOrigin.y -= m_texture.getSize().y / 2;

}

void Catapult::Render(sf::RenderWindow& _window)
{

	_window.draw(m_sprite);
}

void Catapult::LoadBird(Bird* _bird)
{

	m_loadedBird = _bird;
}

void Catapult::MoveBird(sf::RenderWindow& _window)
{

	if (m_loadedBird != nullptr)
	{

		sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);
		m_firingVector.x = mousePosition.x - m_firingOrigin.x;
		m_firingVector.y = mousePosition.y - m_firingOrigin.y;


		float length = sqrt((m_firingVector.x * m_firingVector.x) + (m_firingVector.y * m_firingVector.y));
	
		
		if (length > 100.0f)
		{

			m_firingVector = (m_firingVector / length) * 100.0f;
					
		}
	
			m_loadedBird->m_sprite.setPosition(m_firingOrigin + m_firingVector);
	}

}

void Catapult::LaunchBird(float _scale, b2World& _world)
{
	if (m_loadedBird != nullptr)
	{

		m_loadedBird->Launch(_scale, m_loadedBird->m_sprite.getPosition(), _world);


		float launchStrength = 4.0f;

		b2Vec2 b2LaunchVector;

		b2LaunchVector.x = m_firingVector.x * -1.0f * launchStrength;
		b2LaunchVector.y = m_firingVector.y * -1.0f * launchStrength;

		m_loadedBird->m_body->ApplyLinearImpulseToCenter(b2LaunchVector, true);
		m_loadedBird = nullptr;

	}

}