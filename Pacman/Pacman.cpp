//
// Created by rasyt on 8/27/2022.
//

#include "Pacman.h"
void Pacman::Pacman::RenderPacman(sf::RenderWindow* windowptr) {
    sf::Color yellow(255, 255, 0);
    thepacman.setRadius(25);
    thepacman.setFillColor(yellow);
    thepacman.setOrigin(25,25);
    thepacman.setPosition(xpos + 25, ypos + 25);
}


Pacman::Pacman::Pacman(int row1, int col1) {
    xpos = col1 * 50;
    ypos = row1 * 50;
    rowposy = row1;
    colposx = col1;
}

void Pacman::Pacman::handlePlayerInputPacman(sf::Keyboard::Key key,
                             bool isPressed)
{
    if (key == sf::Keyboard::W)
        uppressed = isPressed;
    else if (key == sf::Keyboard::S)
        downpressed = isPressed;
    else if (key == sf::Keyboard::A)
        leftpressed = isPressed;
    else if (key == sf::Keyboard::D)
        rightpressed = isPressed;
    currentkeydirection = key;
}


void Pacman::Pacman::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (uppressed)
        movement.y -= speed;
        ypos -= speed;
    if (downpressed)
        movement.y += speed;
        ypos += speed;
    if (leftpressed)
        movement.x -= speed;
        xpos -= speed;
    if (rightpressed)
        movement.x += speed;
        xpos += speed;
    thepacman.move(movement * deltaTime.asSeconds());
}

void Pacman::Pacman::PacmanSetDetect()
{
     topleftrect = {ypos, ypos + 25, xpos, xpos + 25};
     toprightrect = {ypos, ypos + 25, xpos + 25, xpos + 50};
     bottomleftrect = {ypos + 25, ypos + 50, xpos, xpos + 25};
     bottomrightrect = {ypos + 25, ypos + 50, xpos + 25, xpos + 50};
}




void Pacman::Pacman::ProcessPacmanMovement(sf::RenderWindow* windowptr, sf::Time timeperframe)
{
    sf::Event event;
    //When I tap the key, I want to keep moving in that direction until I hit a wall
    //set a boolean called movementhold
    while (windowptr->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                if (event.key.code != currentkeydirection
                    and (event.key.code == sf::Keyboard::W or
                         event.key.code == sf::Keyboard::S
                         or event.key.code == sf::Keyboard::A or
                         event.key.code == sf::Keyboard::D))
                {
                    switch (currentkeydirection)
                    {
                        case sf::Keyboard::W:
                            uppressed = false;
                            break;
                        case sf::Keyboard::S:
                            downpressed = false;
                            break;
                        case sf::Keyboard::A:
                            leftpressed = false;
                            break;
                        case sf::Keyboard::D:
                            rightpressed = false;
                            break;
                    }
                }
                std::cout << "key Pressed!" << std::endl;
                handlePlayerInputPacman(event.key.code, true);
                break;
            case sf::Event::Closed:
                windowptr->close();
                break;
        }
    }
    update(timeperframe);
}




