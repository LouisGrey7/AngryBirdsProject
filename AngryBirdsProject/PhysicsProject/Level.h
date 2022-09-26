#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"

#include "Object.h"
#include "Catapult.h"
#include "Bird.h"
#include "Enemy.h"
#include "ContactListener.h"

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
	class ContactListener* m_contactListener;

	Catapult* m_catapult;
	Object* m_ground;
	std::vector<Object*> m_objects;
	std::vector<Bird*> m_birds;
	std::vector<Enemy*> m_enemies;

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

};

