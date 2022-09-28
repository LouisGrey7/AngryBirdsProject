//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Bird.h
// Description	: Bird Class, creates birds with special abilities! Tweet that!
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"

//Four bird types, with room for more if wanting to add.
enum class BIRDTYPE
{
	REDBIRD, //No Special moves, just red and chunky
	YELLOWBIRD, //Speedy bird, goes fast after a certain point
	GREENBIRD, //Boomerang bird, flings back when travelling far enough
	BLUEBIRD //Smol bird, goes fast and can fit in gaps.
};

class Bird
{
private:

	// Box 2D 
	b2BodyDef m_bodyDef;
	b2CircleShape m_shape;
	b2FixtureDef m_fixtureDef;

	//SFML
	sf::Texture m_texture;

public:
	sf::Sprite m_sprite;
	b2Body* m_body;

	Bird(BIRDTYPE _BirdType);
	~Bird();

	void Launch(float _scale, sf::Vector2f _position, b2World& _world);
	void Render(sf::RenderWindow& _window, float _scale);

	void UseSpecialAbility(float _scale);

	inline b2Body* GetBody() { return m_body; };


	BIRDTYPE m_birdtype;
	bool m_Launched = false;
	bool m_AbilityActivated = false;

};

