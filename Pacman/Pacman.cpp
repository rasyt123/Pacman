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


Pacman::Pacman::Pacman(int row1, int col1, std::vector<std::pair<float, float>> rectangleneeds) {
    xpos = col1 * 50;
    ypos = row1 * 50;
    rowposy = row1;
    colposx = col1;
    rectanglelocations = rectangleneeds;
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
    float oldypos = ypos;
    float oldxpos = xpos;
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
     all4rects.clear();
     topleftrect = {ypos, ypos + 25, xpos, xpos + 25};
     toprightrect = {ypos, ypos + 25, xpos + 25, xpos + 50};
     bottomleftrect = {ypos + 25, ypos + 50, xpos, xpos + 25};
     bottomrightrect = {ypos + 25, ypos + 50, xpos + 25, xpos + 50};
     all4rects.push_back(topleftrect);
     all4rects.push_back(toprightrect);
     all4rects.push_back(bottomleftrect);
     all4rects.push_back(bottomrightrect);
}


bool Pacman::Pacman::CollisonCheck() {
    for (std::pair<float, float>& wall : rectanglelocations)
    {
        float wallxleft = wall.first;
        float wallxright = wall.first + 50;
        float wallytop = wall.second;
        float wallybottom = wall.second + 50;
        for (std::vector<float>& rectangle : all4rects)
        {
            //check for an intersection in both planes
            //both  projections must be intersecting for there to be a collision
            if (((wallybottom > rectangle[0] and wallybottom < rectangle[1]) or
                 (wallytop < rectangle[1] and wallytop > rectangle[0]))
                and ((rectangle[2] < wallxright and rectangle[2] > wallxleft)
                     or (wallxleft < rectangle[3] and wallxleft > rectangle[2])))
            {
                return true;
            }
        }
    }
    return false;
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
                handlePlayerInputPacman(event.key.code, true);
                break;
            case sf::Event::Closed:
                windowptr->close();
                break;
        }
    }
    update(timeperframe);
}





