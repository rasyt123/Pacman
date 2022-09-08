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
#include "Animation.h"
namespace Pacman
{
    class Pacman
    {
    public:
        Pacman(int row1, int col1, std::vector<std::pair<float, float>> rectangleneeds, std::shared_ptr<std::vector<std::string>> zacmanmap,
               std::vector<std::pair<float, float>> pelletcoords);
        void RenderPacman(sf::RenderWindow* windowptr, sf::Texture* text);
        void ProcessPacmanMovement(sf::RenderWindow* windowptr, sf::Time timeperframe, Animation& pacmansheet);
        void handlePlayerInputPacman(sf::Keyboard::Key key, bool isPressed);
        void PacmanSetDetect();
        bool NewKeyCheckWallCollide(sf::RenderWindow* windowptr);
        bool CrossesOffScreenLeft();
        bool CrossesOffScreenRight();
        void update(sf::Keyboard::Key keycode, sf::Time deltaTime, sf::RenderWindow* windowptr, Animation& pacmansheet);
        std::vector<float> topleftrect;
        std::vector<float> toprightrect;
        std::vector<float> bottomleftrect;
        std::vector<float> bottomrightrect;
        std::vector<std::vector<float>> all4rects;
        bool CollisonCheck(sf::RenderWindow* windowptr, float pacx, float pacy);
        bool PelletCollision(sf::RenderWindow* windowptr, float pacx, float pacy);

        sf::RectangleShape thepacman;
        float xpos;
        float ypos;
    private:
        sf::Keyboard::Key previouskeydirection;
        sf::Keyboard::Key newkey;
        std::vector<std::pair<float, float>> rectanglelocations;
        std::shared_ptr<std::vector<std::string>> pacmanmap;
        std::vector<std::pair<float, float>> thepelletcoords;
        float speed = 5.0f;
        int count = 0;
        int score = 0;
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

