//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: ContactListener.h
// Description	: box2d Contact listener for collisions
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#pragma once

#include "box2d/b2_world_callbacks.h"

class ContactListener : public b2ContactListener
{

private:



public:

	virtual void BeginContact(b2Contact* contact) override;

	virtual void EndContact(b2Contact* contact) override;
};

