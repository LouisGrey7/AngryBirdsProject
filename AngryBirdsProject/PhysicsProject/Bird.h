#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"

enum class BIRDTYPE
{
	REDBIRD,
	YELLOWBIRD,
	GREENBIRD
};

class Bird
{
private:

	// Box 2D Stuff
	b2BodyDef m_bodyDef;

	b2CircleShape m_shape;
	b2FixtureDef m_fixtureDef;

	//SFML Stuff

	sf::Texture m_texture;

public:
	sf::Sprite m_sprite;
	b2Body* m_body;

	Bird();

	void Launch(float _scale, sf::Vector2f _position, b2World& _world);
	void Render(sf::RenderWindow& _window, float _scale);



};

