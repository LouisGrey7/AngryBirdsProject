#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"
#include "Bird.h"

class Catapult
{
private:
//SFML
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	Bird* m_loadedBird;


	sf::Vector2f m_firingOrigin;
	sf::Vector2f m_firingVector;

public:
	Catapult(sf::Vector2f _position);

	void Render(sf::RenderWindow& _window);

	void LoadBird(Bird* _bird);
	void MoveBird(sf::RenderWindow& _window);
	void LaunchBird(float _scale, b2World& _world);

};

