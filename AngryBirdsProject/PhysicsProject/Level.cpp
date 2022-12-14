//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2022 Media Design School
//
// File Name	: Level.cpp
// Description	: Impliments functionality for Level class
// Author		: David Andrews && Louis Grey
// Mail			: David.Andrews@mds.ac.nz      Louis.Grey@mds.ac.nz
//
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

    windmill = new Windmill(950, 100, m_world);

    rope = new Rope(1250, 25, m_world);

    Load(STAGE1);

}

Level::~Level()
{
    //delete all objects here
    //Unload();

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
    m_CurrentStage = _level;
    BIRDTYPE randBird1 = BIRDTYPE::REDBIRD;
    BIRDTYPE randBird2 = BIRDTYPE::YELLOWBIRD;
    BIRDTYPE randBird3 = BIRDTYPE::GREENBIRD;
    BIRDTYPE randBird4 = BIRDTYPE::BLUEBIRD;
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
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 275.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 275.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 275.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(800.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(900.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
        m_enemies.push_back(new Enemy(sf::Vector2f(1000.0f, 600.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));

        

        break;
    case STAGE2:

        m_ClickCount = 0;

        //Blocks
        m_objects.push_back(new Object(sf::Vector2f(500, 450), 30.0f, b2BodyType::b2_staticBody, "LongBlockV.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(700.0f, 475), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(700.0f, 525), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(700.0f, 575), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));

        m_objects.push_back(new Object(sf::Vector2f(1150, 475), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 525), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));
        m_objects.push_back(new Object(sf::Vector2f(1150, 575), 30.0f, b2BodyType::b2_dynamicBody, "Block.png", m_world));



        //Birds
        m_birds.push_back(new Bird(randBird1));
        m_birds.push_back(new Bird(randBird1));
        m_birds.push_back(new Bird(randBird3));
        m_birds.push_back(new Bird(randBird3));

        //Enemies
        m_enemies.push_back(new Enemy(sf::Vector2f(700.0f, 425.0f), 30.0f, b2BodyType::b2_dynamicBody, "Enemy.png", m_world));
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
        //m_objectstoDestroy.push_back(m_objects[i]);

    }
    for (int i = 0; i < m_birds.size(); ++i)
    {
        m_birdstoDestroy.push_back(m_birds[i]);
        //m_world->DestroyBody(m_birds[i]->GetBody());
    }
    for (int i = 0; i < m_enemies.size(); ++i)
    {
        m_enemiestoDestroy.push_back(m_enemies[i]);

        //m_world->DestroyBody(m_enemies[i]->GetBody()); 
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
            if ((float)m_birds[i]->m_sprite.getPosition().x > 1100.0f && !m_birds[i]->m_AbilityActivated)
            {
                m_birds[i]->UseSpecialAbility(_scale);
                m_birds[i]->m_AbilityActivated = true;
            }
        }
        else if (m_birds[i]->m_birdtype == BIRDTYPE::BLUEBIRD)
        {
            if ((float)m_birds[i]->m_sprite.getPosition().x > 800.0f && !m_birds[i]->m_AbilityActivated)
            {
                m_objects.push_back(new Object(sf::Vector2f(m_birds[i]->m_sprite.getPosition().x, m_birds[i]->m_sprite.getPosition().y), 30.0f, b2BodyType::b2_dynamicBody, "Bomb.png", m_world));
                m_objects.push_back(new Object(sf::Vector2f(m_birds[i]->m_sprite.getPosition().x + 25, m_birds[i]->m_sprite.getPosition().y), 30.0f, b2BodyType::b2_dynamicBody, "Bomb.png", m_world));
                m_objects.push_back(new Object(sf::Vector2f(m_birds[i]->m_sprite.getPosition().x + 50, m_birds[i]->m_sprite.getPosition().y), 30.0f, b2BodyType::b2_dynamicBody, "Bomb.png", m_world));
                m_objects.push_back(new Object(sf::Vector2f(m_birds[i]->m_sprite.getPosition().x + 75, m_birds[i]->m_sprite.getPosition().y), 30.0f, b2BodyType::b2_dynamicBody, "Bomb.png", m_world));

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
    windmill->Render(_window, _scale);
    rope->Render(_window, _scale);

}

void Level::Update()
{

    m_enemyCount = (int)m_enemies.size();
    if (m_enemyCount <= 0)
    {
        Unload();

        if (m_CurrentStage == Stage::STAGE1)
        {
            Load(Stage::STAGE2);
        }
        else if (m_CurrentStage == Stage::STAGE2)
        {
            Load(Stage::STAGE3);
        }
        else
        {
            Load(Stage::STAGE1);
        }


    }
    // world step
    m_world->Step(1.0f / 60.0f, 8, 3);

    for (int i = 0; i < m_birds.size(); ++i)
    {
        if (m_birds[i]->m_sprite.getPosition().x >= 1290.0f || m_birds[i]->m_sprite.getPosition().x <= -10.0f
            || m_birds[i]->m_sprite.getPosition().y >= 730.0f || m_birds[i]->m_sprite.getPosition().y <= -10.0f)
        {
            //Delete the object that goes out of bounds (OFF SCREEN)
            //m_birdstoDestroy.push_back(m_birds[i]);
            //m_birds.erase(m_birds.begin() + i);

            
        }
    }
    

    for (int i = 0; i < m_enemies.size(); ++i)
    {
        if (m_enemies[i]->m_health <= 0)
        {
            m_enemiestoDestroy.push_back(m_enemies[i]);
            m_enemies.erase(m_enemies.begin() + i);
        }
    }
    

    if (m_objectstoDestroy.size() != 0 && !m_world->IsLocked())
    {
        for (int i = 0; i < m_objectstoDestroy.size(); ++i)
        {
            delete m_objectstoDestroy[i];
        }
        m_objectstoDestroy.clear();
    }

    if (m_birdstoDestroy.size() != 0 && !m_world->IsLocked())
    {
        for (int i = 0; i < m_birdstoDestroy.size(); ++i)
        {
            delete m_birdstoDestroy[i];
        }
            m_birdstoDestroy.clear();
    }

    if (m_enemiestoDestroy.size() != 0 && !m_world->IsLocked())
    {
        for (int i = 0; i < m_enemiestoDestroy.size(); ++i)
        {
            delete m_enemiestoDestroy[i];
        }
        m_enemiestoDestroy.clear();
    }
}
