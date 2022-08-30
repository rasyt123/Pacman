//
// Created by rasyt on 8/27/2022.
//

#include "Pacman.h"
void Pacman::Pacman::RenderPacman(int row, int col, sf::RenderWindow* windowptr) {
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::Color yellow(255, 255, 0);
    Pacman.setRadius(25);
    Pacman.setFillColor(yellow);
    Pacman.setOrigin(25,25);
    Pacman.setPosition(floatposx + 25, floatposy + 25);
    xpos = floatposx;
    ypos = floatposy;
    windowptr->draw(Pacman);
    rowposy = row;
    rowposx = col;
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
    if (downpressed)
        movement.y += speed;
    if (leftpressed)
        movement.x -= speed;
    if (rightpressed)
        movement.x += speed;
    Pacman.move(movement * deltaTime.asSeconds());
}




void Pacman::Pacman::ProcessPacmanMovement(sf::RenderWindow* windowptr) {
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
                    switch (event.key.code)
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
                handlePlayerInputPacman(event.key.code, true);
                break;
            case sf::Event::Closed:
                windowptr->close();
                break;
        }
    }
}


