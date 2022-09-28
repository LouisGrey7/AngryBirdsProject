//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: ContactListener.cpp
// Description	: Handles contact between two objects
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#include "ContactListener.h"
#include "box2d/b2_settings.h"

#include "Object.h"

void ContactListener::BeginContact(b2Contact* contact)
{
	auto bodyuserDataA = (Object*)contact->GetFixtureA()->GetBody()->GetUserData().pointer;
	auto bodyuserDataB = (Object*)contact->GetFixtureB()->GetBody()->GetUserData().pointer;


	if (bodyuserDataA && bodyuserDataB)
	{

		bodyuserDataA->StartContact(bodyuserDataB);
		bodyuserDataB->StartContact(bodyuserDataA);

	}
	


}

void ContactListener::EndContact(b2Contact* contact)
{
	auto bodyuserDataA = (Object*)contact->GetFixtureA()->GetBody()->GetUserData().pointer;
	auto bodyuserDataB = (Object*)contact->GetFixtureB()->GetBody()->GetUserData().pointer;


	if (bodyuserDataA && bodyuserDataB)
	{

		bodyuserDataA->EndContact(bodyuserDataB);
		bodyuserDataB->EndContact(bodyuserDataA);

	}

}
