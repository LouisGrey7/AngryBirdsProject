//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Windmill.h
// Description	: Class that creates a rotating block object
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
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

