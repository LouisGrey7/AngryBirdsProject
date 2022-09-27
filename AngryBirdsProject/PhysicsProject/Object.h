#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"


class Object
{
private:

	// Box 2D Stuff
	b2BodyDef m_bodyDef;

	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;

	//SFML Stuff

	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:

	b2Body* m_body;
	Object(sf::Vector2f _position, float _scale, b2BodyType _bodytype, std::string _spritename, b2World* _world);
	~Object();

	
	void Render(sf::RenderWindow& _window, float _scale);

	virtual void StartContact(Object* other);
	virtual void EndContact(Object* other);


	inline b2Body* GetBody() { return m_body;}


};

