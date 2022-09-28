//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Enemy.h
// Description	: Enemy class, Miss Pig has a manager and here they are...
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#pragma once
#include <iostream>

#include "Object.h"
class Enemy :
    public Object
{
private:




public:
    int m_health = 5;
    using Object::Object;

    void TakeDamage();

    void StartContact(Object* other) override;
    void EndContact(Object* other) override;

};

