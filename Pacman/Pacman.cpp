//
// Created by rasyt on 8/27/2022.
//

#include "Pacman.h"
void Pacman::Pacman::RenderPacman(sf::RenderWindow* windowptr) {
    sf::Color yellow(255, 255, 0);
    thepacman.setRadius(25);
    thepacman.setFillColor(yellow);
    thepacman.setOrigin(25, 25);
    thepacman.setPosition(xpos + 25, ypos + 25);
}


Pacman::Pacman::Pacman(int row1, int col1, std::vector<std::pair<float, float>> rectangleneeds) {
    xpos = col1 * 50;
    ypos = row1 * 50;
    rowposy = row1;
    colposx = col1;
    rectanglelocations = rectangleneeds;
    PacmanSetDetect();
}

void Pacman::Pacman::handlePlayerInputPacman(sf::Keyboard::Key key,
                             bool isPressed)
{
    previouskeydirection = key;
}


bool Pacman::Pacman::CrossesOffScreenLeft()
{
    float topleftx = 0;
    sf::Vector2f pacposition = thepacman.getPosition();
    if (pacposition.x <= topleftx)
    {
        thepacman.setPosition((18 * 50) - 5, pacposition.y);
        return true;
    }
    return false;
}


bool Pacman::Pacman::CrossesOffScreenRight()
{
    sf::Vector2f pacposition = thepacman.getPosition();
    if (pacposition.x >= 18 * 50)
    {
        thepacman.setPosition(5, pacposition.y);
        return true;
    }
    return false;
}


void Pacman::Pacman::update(sf::Keyboard::Key keycode, sf::Time deltaTime, sf::RenderWindow* windowptr)
{
    sf::Vector2f movement(0.f, 0.f);
    sf::Vector2f oldposition = thepacman.getPosition();
    if (keycode == sf::Keyboard::W)
        movement.y -= speed;
    if (keycode == sf::Keyboard::S)
        movement.y += speed;
    if (keycode == sf::Keyboard::A)
        movement.x -= speed;
    if (keycode == sf::Keyboard::D)
        movement.x += speed;
    thepacman.move(movement);
    sf::Vector2f pos = thepacman.getPosition();
    xpos = pos.x - 25;
    ypos = pos.y - 25;
    if (CollisonCheck(windowptr, xpos, ypos))
    {
        thepacman.setPosition(oldposition);
        xpos = oldposition.x;
        ypos = oldposition.y;
    }
}

bool Pacman::Pacman::NewKeyCheckWallCollide(sf::RenderWindow* windowptr) {
    sf::Vector2f newpos = thepacman.getPosition();
    float currnewposx = newpos.x;
    float currnewposy = newpos.y;
    if (newkey == sf::Keyboard::W)
    {
        currnewposy -= speed;
    }
    else if (newkey == sf::Keyboard::S)
    {
        currnewposy += speed;
    }
    else if (newkey == sf::Keyboard::A)
    {
        currnewposx -= speed;
    } else if (newkey == sf::Keyboard::D)
    {
        currnewposx += speed;
    }
    return CollisonCheck(windowptr, currnewposx -25, currnewposy -25);
}



void Pacman::Pacman::PacmanSetDetect() {
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

bool Pacman::Pacman::CollisonCheck(sf::RenderWindow* windowptr, float pacx, float pacy) {
    int counter = 0;
    bool hascollision = false;
    for (std::pair<float, float> wall : rectanglelocations)
    {
            float wallxleft = wall.first;
            float wallxright = wall.first + 50;
            float wallytop = wall.second;
            float wallybottom = wall.second + 50;
        //wall will be rectangle B
            //check for an intersection in both planes
            //both  projections must be intersecting for there to be a collision
            //pacman will be rectangle A
            float pacrectleft = pacx;
            float pacrectright = pacx + 50;
            float pactrecttop = pacy;
            float pactrectbottom = pacy + 50;
            if ((pacrectleft < wallxright and pacrectright > wallxleft)
            and (pactrecttop < wallybottom and pactrectbottom > wallytop))
            {
                sf::RectangleShape jboy(sf::Vector2f(50, 50));
                sf::Color whatcolor (255, 0, 0);
                jboy.setPosition(wall.first, wall.second);
                jboy.setFillColor(whatcolor);
                windowptr->draw(jboy);
                std::cout << "x of pacrect " << xpos << std::endl;
                std::cout << "y of pacrect " << ypos << std::endl;
                sf::Vector2f currpos = thepacman.getPosition();
                std::cout << "center x of sprite pac: " << currpos.x << std::endl;
                std::cout << "center y of sprite pac: " << currpos.y << std::endl;

                hascollision = true;
            }
    }
    if (hascollision) {
        return true;
    }
    return false;
}

void Pacman::Pacman::ProcessPacmanMovement(sf::RenderWindow* windowptr, sf::Time timeperframe)
{
    sf::Event event;
    //When I tap the key, I want to keep moving in that direction until I hit a wall
    //set a boolean called movementhold


    //When I change keys, save the new key and try movement on it and if I run into a wall,
    //keep moving in the old direction (but testing the new direction at every frame/position )
    while (windowptr->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                if (event.key.code != previouskeydirection
                    and (event.key.code == sf::Keyboard::W or
                         event.key.code == sf::Keyboard::S
                         or event.key.code == sf::Keyboard::A or
                         event.key.code == sf::Keyboard::D))
                {
                    newkey = event.key.code;
                }
                //only want this to execute when new key has no collision
                if (count == 0)
                {
                    handlePlayerInputPacman(event.key.code, true);
                    count += 1;
                }
                break;
            case sf::Event::Closed:
                windowptr->close();
                break;
        }
    }
    if (newkey != sf::Keyboard::Unknown and !NewKeyCheckWallCollide(windowptr))
    {
        update(newkey, timeperframe,windowptr);
        previouskeydirection = newkey;
        newkey = sf::Keyboard::Unknown;
    } else {
        update(previouskeydirection, timeperframe, windowptr);
    }

}

