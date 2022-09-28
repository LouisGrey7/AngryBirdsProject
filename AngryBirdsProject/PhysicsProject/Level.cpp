#include "Level.h"
#include <iostream>

Level::Level(float _scale)
{

    //create world
    b2Vec2 m_gravity(0.0, 10.f);
    m_world = new b2World (m_gravity);

    m_contactListener = new ContactListener();
    m_world->SetContactListener(m_contactListener);

    m_ground = new Object(sf::Vector2f(640, 700), 30.0f, b2BodyType::b2_staticBody, "Ground.png", m_world);

    m_catapult = new Catapult(sf::Vector2f(120, 550));


    Load(STAGE3);

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
    if(m_ClickCount < 4)
    {
        m_catapult->LoadBird(m_birds[m_ClickCount]);
        m_catapult->MoveBird(_window);
        m_ClickCount += 1;
    }
    else if (m_ClickCount == 4)
    {
        std::cout << "USED ALL BIRDS!" << std::endl;
    }

    
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
    
    int randBird1 = 0;
    int randBird2 = 1;
    int randBird3 = 2;
    int randBird4 = 3;
    //int randBird4 = rand() % 3;

    switch (_level)
    {

    case STAGE1:
        m_ClickCount = 0;

        //Blocks
        m_objects.push_back(new Object(sf::Vector2f(750, 600), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(750, 400), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1100, 600), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1100, 400), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(925, 475), 30.0f, b2BodyType::b2_dynamicBody, "LongBlockH.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(925, 350), 30.0f, b2BodyType::b2_dynamicBody, "LongBlockH.png", m_world));

        
        //Birds
        m_birds.push_back(new Bird(randBird1));
        m_birds.push_back(new Bird(randBird2));
        m_birds.push_back(new Bird(randBird3));
        m_birds.push_back(new Bird(randBird4));

        //Enemies
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 250.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 250.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 250.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 400.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 400.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 400.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));

        

        break;
    case STAGE2:

        m_ClickCount = 0;

        //Blocks
        m_objects.push_back(new Object(sf::Vector2f(800, 400), 30.0f, b2BodyType::b2_staticBody, "LongBlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 475), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 525), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 575), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));

        m_objects.push_back(new Object(sf::Vector2f(1150, 475), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 525), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 575), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));



        //Birds
        m_birds.push_back(new Bird(randBird3));
        m_birds.push_back(new Bird(randBird3));
        m_birds.push_back(new Bird(randBird3));
        m_birds.push_back(new Bird(randBird3));

        //Enemies
        m_enemies.push_back(new Enemy(sf::Vector2f(950.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1150.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        

        break;
    case STAGE3:

        m_ClickCount = 0;

        //Blocks
        m_objects.push_back(new Object(sf::Vector2f(650, 550), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(650, 450), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(650, 350), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(650, 250), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(650, 150), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(650, 50), 30.0f, b2BodyType::b2_dynamicBody, "BlockV.png", m_world));

        m_objects.push_back(new Object(sf::Vector2f(750, 500), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(750, 300), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(750, 100), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 550), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 350), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(950, 150), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 500), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 300), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 100), 30.0f, b2BodyType::b2_staticBody, "StaticBlock.png", m_world));


        //Birds
        m_birds.push_back(new Bird(randBird2));
        m_birds.push_back(new Bird(randBird4));
        m_birds.push_back(new Bird(randBird4));
        m_birds.push_back(new Bird(randBird4));


        //Enemies
        m_enemies.push_back(new Enemy(sf::Vector2f(750.0f, 450.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(750.0f, 250.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(750.0f, 50.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));

        m_enemies.push_back(new Enemy(sf::Vector2f(950.0f, 500.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(950.0f, 300.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(950.0f, 100.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));

        m_enemies.push_back(new Enemy(sf::Vector2f(1150.0f, 450.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1150.0f, 250.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1150.0f, 50.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));

        break;

    }
}

void Level::Unload()
{

    for (int i = 0; i < m_objects.size(); ++i)
    {
        m_world->DestroyBody(m_objects[i]->GetBody());
    }
    for (int i = 0; i < m_birds.size(); ++i)
    {
        m_birdstoDestroy.push_back(m_birds[i]);
        //m_world->DestroyBody(m_birds[i]->GetBody());
    }
    for (int i = 0; i < m_enemies.size(); ++i)
    {
        m_world->DestroyBody(m_enemies[i]->GetBody()); 
    }
    m_objects.clear();
    m_birds.clear();
    m_enemies.clear();

}

void Level::Render(sf::RenderWindow& _window, float _scale)
{

    m_ground->Render(_window, _scale);

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
    for (int i = 0; i < m_enemies.size(); ++i)
    {
        m_enemies[i]->Render(_window, _scale);
    }
    m_catapult->Render(_window);

}

void Level::Update()
{
    // world step
    m_world->Step(1.0f / 60.0f, 8, 3);

    //for (int i = 0; i < m_birds.size(); ++i)
    //{
    //    if (m_birds[i]->m_sprite.getPosition().x >= 1290.0f || m_birds[i]->m_sprite.getPosition().x <= -10.0f
    //        || m_birds[i]->m_sprite.getPosition().y >= 730.0f || m_birds[i]->m_sprite.getPosition().y <= -10.0f)
    //    {
    //        //Delete the object that goes out of bounds (OFF SCREEN)
    //        m_birds[i]->GetBody()->DestroyFixture(m_birds[i]->GetBody()->GetFixtureList());
    //        
    //    }
    //}
    
    for (auto enemy : m_enemies)
    {
        enemy->Destroy();
    }


    if (m_birdstoDestroy.size() != 0 && !m_world->IsLocked())
    {
        for (int i = 0; i < m_birdstoDestroy.size(); ++i)
        {
            m_world->DestroyBody(m_birdstoDestroy[i]->GetBody());
            m_birdstoDestroy.clear();
        }
    }
}
