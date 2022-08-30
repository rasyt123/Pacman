//
// Created by rasyt on 8/27/2022.
//

#include "Game.h"
void Pacman::Game::PacGameLoop() {
    //each tile 50 pixels wide 50 pixels tall
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::RenderWindow pacwindow(sf::VideoMode(50 * pacmanmap[0].size(), 50 * pacmanmap.size()), "Pacman", sf::Style::Close | sf::Style::Titlebar);
    sf::Time TimePerFrame;
    TimePerFrame = sf::seconds(1.f / 60.f);
    DrawMap(&pacwindow);
    while (pacwindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
        }

        pacwindow.display();
        pacwindow.clear();

    }
}

void Pacman::Game::RenderWall(int row, int col, sf::RenderWindow* windowptr)
{
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::RectangleShape wall(sf::Vector2f(50, 50));
    sf::Color blue (0, 0, 255);
    wall.setPosition(floatposx, floatposy);
    wall.setFillColor(blue);
    windowptr->draw(wall);
}

void Pacman::Game::RenderPellet(int row, int col, sf::RenderWindow* windowptr) {
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::Color white(255, 255, 255);
    sf::CircleShape pellet(5);
    pellet.setFillColor(white);
    pellet.setOrigin(5,5);
    pellet.setPosition(floatposx + 25, floatposy + 25);
    windowptr->draw(pellet);
}



void Pacman::Game::RenderPowerPellet(int row, int col, sf::RenderWindow* windowptr) {
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::Color white(255, 255, 255);
    sf::CircleShape bigpellet(10);
    bigpellet.setFillColor(white);
    bigpellet.setOrigin(10,10);
    bigpellet.setPosition(floatposx + 25, floatposy + 25);
    windowptr->draw(bigpellet);
}


void Pacman::Game::DrawMap(sf::RenderWindow* windowptr) {
    int dotcounter = 0;
    for (int y = 0; y  < pacmanmap.size(); y++)
    {
        for (int x = 0; x < pacmanmap[0].size(); x++)
        {
            switch (pacmanmap[y][x])
            {
                case '#':
                    RenderWall(y, x, windowptr);
                    break;
                case '.':
                    RenderPellet(y, x, windowptr);
                    break;
                case 'o':
                    RenderPowerPellet(y, x, windowptr);
                    break;
            }
        }
    }
}