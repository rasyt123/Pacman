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
        Pacman(int row1, int col1, std::vector<std::pair<float, float>> rectangleneeds);
        void RenderPacman(sf::RenderWindow* windowptr);
        void ProcessPacmanMovement(sf::RenderWindow* windowptr, sf::Time timeperframe);
        void handlePlayerInputPacman(sf::Keyboard::Key key, bool isPressed);
        void PacmanSetDetect();
        bool NewKeyCheckWallCollide(sf::RenderWindow* windowptr);
        void update(sf::Keyboard::Key keycode, sf::Time deltaTime, sf::RenderWindow* windowptr);
        std::vector<float> topleftrect;
        std::vector<float> toprightrect;
        std::vector<float> bottomleftrect;
        std::vector<float> bottomrightrect;
        std::vector<std::vector<float>> all4rects;
        bool CollisonCheck(sf::RenderWindow* windowptr, float pacx, float pacy);

        sf::CircleShape thepacman;
        float xpos;
        float ypos;
    private:
        sf::Keyboard::Key previouskeydirection;
        sf::Keyboard::Key newkey;
        std::vector<std::pair<float, float>> rectanglelocations;
        float speed = 5.0f;
        int count = 0;
        int rowposy;
        int colposx;
        bool uppressed = false;
        bool downpressed = false;
        bool leftpressed = false;
        bool rightpressed = false;
        std::string currentdirection;
    };
}



#endif //PACMAN_PACMAN_H

