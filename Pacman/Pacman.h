//
// Created by rasyt on 8/27/2022.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Pacman
{
    class Pacman
    {
        void RenderPacman(int row, int col, sf::RenderWindow* windowptr);
        void ProcessPacmanMovement(sf::RenderWindow* windowptr);
        void handlePlayerInputPacman(sf::Keyboard::Key key, bool isPressed);
        void update(sf::Time deltaTime);

    private:
        sf::CircleShape Pacman;
        sf::Keyboard::Key currentkeydirection;
        float speed = 1.0f;
        int rowposy;
        int rowposx;
        float xpos;
        float ypos;
        bool uppressed = false;
        bool downpressed = false;
        bool leftpressed = false;
        bool rightpressed = false;
        std::string currentdirection;
    };
}



#endif //PACMAN_PACMAN_H
