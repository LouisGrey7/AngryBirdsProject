#include "SFML/Graphics.hpp"
#include "box2d\box2D.h"

#include "Level.h"

#include <iostream>

int main()
{
    const double SCALE = 30.0;
 
    //window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Angry Birds");
    window.setFramerateLimit(60);

    Level* level = new Level(SCALE);

    while (window.isOpen())
    {
        window.clear(sf::Color(97,136,235));

        //Poll Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) //Pressing L will unload current and load next stage
            {
                level->Unload();
                if (level->GetCurrentStage() == Stage::STAGE1)
                {
                    level->Load(Stage::STAGE2);
                }
                else if (level->GetCurrentStage() == Stage::STAGE2)
                {
                    level->Load(Stage::STAGE3);
                }
                else
                {
                    level->Load(Stage::STAGE1);
                }
                
            }

            switch (event.type)
            {
                case sf::Event::MouseButtonPressed: //Triggers bird being loaded into catapult
                {
                    level->MouseButtonPressed(window);
                        

                    break;

                }
                case sf::Event::MouseButtonReleased: //Fires the bird
                {

                    level->MouseButtonReleased();
                    break;

                }
                case sf::Event::MouseMoved: //Updates the bird position if on screen when in catapult
                {

                    level->MouseMoved(window);
                    break;

                }
            }
        }


        level->Update();
        level->Render(window, SCALE);

        window.display();
    }

    return 0;
}