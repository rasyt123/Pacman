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
    public:
        Pacman(int row1, int col1);
        void RenderPacman(sf::RenderWindow* windowptr);
        void ProcessPacmanMovement(sf::RenderWindow* windowptr, sf::Time timeperframe);
        void handlePlayerInputPacman(sf::Keyboard::Key key, bool isPressed);
        void update(sf::Time deltaTime);

        sf::CircleShape thepacman;
    private:
        sf::Keyboard::Key currentkeydirection;
        float speed = 300.0f;
        int rowposy;
        int colposx;
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
