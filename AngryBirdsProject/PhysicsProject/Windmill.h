#pragma once


#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"
#include "Object.h"

class Windmill
{

private:
	Object* boxV;
	Object* boxH;


	b2RevoluteJoint* joint;
	b2RevoluteJointDef RJD;

public:

	Windmill(float x, float y, b2World* world);
	~Windmill();

	void Render(sf::RenderWindow& _window, float _scale);

};

