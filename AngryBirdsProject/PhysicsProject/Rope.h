#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"
#include "Object.h"


class Rope
{

private:
	Object* box1;
	Object* box2;
	Object* box3;
	Object* box4;

	std::vector<Object*> boxes;
	std::vector<b2DistanceJointDef*> DJDs;

	b2DistanceJoint* joint;
	b2DistanceJoint* joint2;
	b2DistanceJoint* joint3;

	b2DistanceJointDef DJD;
	b2DistanceJointDef DJD2;
	b2DistanceJointDef DJD3;

public:

	Rope(float x, float y, b2World* world);
	~Rope();

	void Render(sf::RenderWindow& _window, float _scale);


};

