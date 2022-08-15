#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"


class Object
{
private:

	// Box 2D Stuff
	b2BodyDef m_bodyDef;
	b2Body* m_body;

	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;

	//SFML Stuff

	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:

	Object(sf::Vector2f _position, float _scale, b2BodyType _bodytype, std::string _spritename, b2World* _world);
	
	void Render(sf::RenderWindow& _window, float _scale);
};

