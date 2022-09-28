#pragma once
#include "SFML/Graphics.hpp"
#include "Bird.h"
#include "Object.h"
class BirdRope
{
public:
	BirdRope(float _SpringConstant, float _RestLength, Object* _Anchor, Bird* _Bob);
	~BirdRope() {};
	void Update();
	void Render(sf::RenderWindow& _window);


private:
	float m_RestLength;
	float m_SpringConstant;
	Object* m_Anchor;
	Bird* m_Bob;

	sf::Vertex line[2];


	//Private functions for this class only
	sf::Vector2f Normalize(const sf::Vector2f& source)
	{
		float length = sqrt((source.x * source.x) + (source.y * source.y));
		if (length != 0)
		{
			return sf::Vector2f(source.x / length, source.y / length);
		}
		else
		{
			return source;
		}
	}

	float length(const sf::Vector2f& source)
	{
		auto R_x = source.x;
		auto R_y = source.y;
		return std::sqrt(R_x * R_x + R_y * R_y);
	}
};

