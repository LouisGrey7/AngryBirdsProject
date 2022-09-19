#include "Level.h"

Level::Level(float _scale)
{

    //create world
    b2Vec2 m_gravity(0.0, 10.f);
    m_world = new b2World (m_gravity);

    contactListener = new ContactListener();
    m_world->SetContactListener(contactListener);

    m_objects.push_back(new Object(sf::Vector2f(480, 500), _scale, b2BodyType::b2_staticBody, "Ground.png", m_world));


    //3 dynamic balls
    for (int i = 0; i < 3; ++i)
    {
        m_objects.push_back(new Object(sf::Vector2f(550 + i * 100, 100), _scale, b2BodyType::b2_dynamicBody, "Ball.png", m_world));
    }

    m_catapult = new Catapult(sf::Vector2f(250, 410));
}

Level::~Level()
{
    //delete all objects here

    //delete contact listener
    if (contactListener != nullptr)
    {
        delete contactListener;

        contactListener = nullptr;

    }
    if (m_world != nullptr)
    {
        delete m_world;
        m_world = nullptr;
    }


}

void Level::MouseButtonPressed(sf::RenderWindow& _window)
{
    m_birds.push_back(new Bird());

    m_catapult->LoadBird(m_birds[m_birds.size() - 1]);
    m_catapult->MoveBird(_window);
}

void Level::MouseButtonReleased()
{
    m_catapult->LaunchBird(30.0f, *m_world);
}

void Level::MouseMoved(sf::RenderWindow& _window)
{
    m_catapult->MoveBird(_window);
}

void Level::Render(sf::RenderWindow& _window, float _scale)
{

    for (int i = 0; i < m_objects.size(); ++i)
    {
        m_objects[i]->Render(_window, _scale);
    }
    for (int i = 0; i < m_birds.size(); ++i)
    {
        m_birds[i]->Render(_window, _scale);
    }

    m_catapult->Render(_window);

}

void Level::Update()
{
    m_world->Step(1.0f / 60.0f, 8, 3);
}
