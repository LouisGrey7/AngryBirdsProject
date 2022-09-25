#include "Level.h"

Level::Level(float _scale)
{

    //create world
    b2Vec2 m_gravity(0.0, 10.f);
    m_world = new b2World (m_gravity);

    m_contactListener = new ContactListener();
    m_world->SetContactListener(m_contactListener);

    m_ground = new Object(sf::Vector2f(640, 700), 30.0f, b2BodyType::b2_staticBody, "Ground.png", m_world);

    m_catapult = new Catapult(sf::Vector2f(120, 550));

    Load(STAGE1);

}

Level::~Level()
{
    //delete all objects here
    Unload();

    //delete contact listener
    if (m_contactListener != nullptr)
    {
        delete m_contactListener;

        m_contactListener = nullptr;

    }
    if (m_world != nullptr)
    {
        delete m_world;
        m_world = nullptr;
    }


}

void Level::MouseButtonPressed(sf::RenderWindow& _window)
{
    int randBird = rand() % 3;
    m_birds.push_back(new Bird(randBird));

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

void Level::Load(Stage _level)
{
    switch (_level)
    {

    case STAGE1:

        m_objects.push_back(new Object(sf::Vector2f(800, 600), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1100, 600), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 300), 30.0f, b2BodyType::b2_dynamicBody, "LongBlockH.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 300), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));


        //3 dynamic balls
        for (int i = 0; i < 3; ++i)
        {
            m_objects.push_back(new Object(sf::Vector2f(800.0f + i * 150.0f, 100.0f), 30.0f, b2BodyType::b2_dynamicBody, "Goon5.png", m_world));
        }

        break;
    case STAGE2:

        //3 dynamic balls
        for (int i = 0; i < 3; ++i)
        {
            m_objects.push_back(new Object(sf::Vector2f(800.0f + i * 150.0f, 100.0f), 30.0f, b2BodyType::b2_dynamicBody, "Ball.png", m_world));
        }

        break;
    case STAGE3:


        //3 dynamic balls
        for (int i = 0; i < 3; ++i)
        {
            m_objects.push_back(new Object(sf::Vector2f(800.0f + i * 150.0f, 100.0f), 30.0f, b2BodyType::b2_dynamicBody, "Ball.png", m_world));
        }

        break;

    }
}

void Level::Unload()
{

    for (int i = 0; i < m_objects.size(); ++i)
    {
        m_world->DestroyBody(m_objects[i]->GetBody());
    }
    m_objects.clear();
    m_birds.clear();

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
        if(m_birds[i]->m_birdtype == BIRDTYPE::GREENBIRD)
        {
            if ((float)m_birds[i]->m_sprite.getPosition().x > 1200.0f && !m_birds[i]->m_AbilityActivated)
            {
                m_birds[i]->UseSpecialAbility(_scale);
                m_birds[i]->m_AbilityActivated = true;
            }
        }
        else
        {
            if ((float)m_birds[i]->m_sprite.getPosition().x > 400.0f && !m_birds[i]->m_AbilityActivated)
            {
                m_birds[i]->UseSpecialAbility(_scale);
                m_birds[i]->m_AbilityActivated = true;
            }
        }
        
    }

    m_ground->Render(_window, _scale);
    m_catapult->Render(_window);

}

void Level::Update()
{
    m_world->Step(1.0f / 60.0f, 8, 3);
    for (int i = 0; i < m_birds.size(); ++i)
    {
        if (m_birds[i]->m_sprite.getPosition().x >= 1290.0f || m_birds[i]->m_sprite.getPosition().x <= -10.0f
            || m_birds[i]->m_sprite.getPosition().y >= 730.0f || m_birds[i]->m_sprite.getPosition().y <= -10.0f)
        {
            //Delete the object somehow
            m_world->DestroyBody(m_birds[i]->m_body);
            
        }
    }
    
}
