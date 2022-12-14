//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Level.h
// Description	: Level class, loads, deletes and keeps track of events in each level.
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"

#include "Object.h"
#include "Catapult.h"
#include "Bird.h"
#include "Enemy.h"
#include "ContactListener.h"
#include "Windmill.h"
#include "Rope.h"

enum Stage
{
	STAGE1,
	STAGE2,
	STAGE3

};

class Level
{
private:

	b2World* m_world;
	Stage m_CurrentStage;
	class ContactListener* m_contactListener;

	Catapult* m_catapult;
	Object* m_ground;
	std::vector<Object*> m_objects;
	std::vector<Bird*> m_birds;
	std::vector<Enemy*> m_enemies;

	std::vector<Object*> m_objectstoDestroy;
	std::vector<Bird*> m_birdstoDestroy;
	std::vector<Enemy*> m_enemiestoDestroy;
	Windmill* windmill;
	Rope* rope;

	int m_ClickCount = 0;
	int m_enemyCount = 0;

public:

	//Constructor Destructor
	Level(float _scale);
	~Level();

	//Functions

	void MouseButtonPressed(sf::RenderWindow& _window);
	void MouseButtonReleased();
	void MouseMoved(sf::RenderWindow& _window);

	void Load(Stage _level);
	void Unload();
	void Render(sf::RenderWindow& _window, float _scale);
	void Update();

	Stage GetCurrentStage() { return m_CurrentStage; }
};

