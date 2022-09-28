//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Enemy.cpp
// Description	: Functionality for Enemy class. 
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#include "Enemy.h"


//Take damage on fall or on hit by bird
void Enemy::TakeDamage()
{

	m_health--;

}

void Enemy::StartContact(Object* other)
{
	TakeDamage();
	std::cout << m_health << "\n";
}

void Enemy::EndContact(Object* other)
{


}
