#pragma once

#include "SFML/Graphics.hpp"
#include "box2d\box2d.h"

#include "Object.h"
#include "Catapult.h"
#include "Bird.h"
#include "ContactListener.h"


class Level
{
private:

	b2World* m_world;
	class ContactListener* contactListener;


	Catapult* m_catapult;
	std::vector<Object*> m_objects;
	std::vector<Bird*> m_birds;

public:

	//Constructor Destructor
	Level(float _scale);
	~Level();
	//Functions

	void MouseButtonPressed(sf::RenderWindow& _window);
	void MouseButtonReleased();
	void MouseMoved(sf::RenderWindow& _window);


	void Render(sf::RenderWindow& _window, float _scale);
	void Update();

};

