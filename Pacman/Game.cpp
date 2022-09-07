//
// Created by rasyt on 8/27/2022.
//

#include "Game.h"

#include <memory>
void Pacman::Game::PacGameLoop() {
    //each tile 50 pixels wide 50 pixels tall
    bool once = true;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::RenderWindow pacwindow(sf::VideoMode(50 * pacmanmap[0].size(), 50 * pacmanmap.size()), "Pacman", sf::Style::Close | sf::Style::Titlebar);
    sf::Time TimePerFrame;
    TimePerFrame = sf::seconds(1.f / 60.f);
    pacwindow.setFramerateLimit(60);
    auto pacmanmappointer = std::make_shared<std::vector<std::string>>(pacmanmap);
    DrawMap(&pacwindow, once, pacmanmappointer);
    std::cout << "Pellet coords size: " << pelletcoords.size() << std::endl;
    Pacman pacman1(1, 2, rectanglecoords, pacmanmappointer, pelletcoords);
    pacman1.RenderPacman(&pacwindow);
    pacwindow.draw(pacman1.thepacman);
    once = false;
    while (pacwindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            pacwindow.clear();
            DrawMap(&pacwindow, once, pacmanmappointer);
            pacman1.ProcessPacmanMovement(&pacwindow, TimePerFrame);
            std::cout << pacmanmap[1][2] << std::endl;
            pacwindow.draw(pacman1.thepacman);
            pacwindow.display();
        }
    }
}


void Pacman::Game::RenderWall(int row, int col, sf::RenderWindow* windowptr, bool once)
{
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::RectangleShape wall(sf::Vector2f(50, 50));
    sf::Color blue (0, 0, 255);
    wall.setPosition(floatposx, floatposy);
    wall.setFillColor(blue);
    windowptr->draw(wall);
    if (once)
    {
        std::pair<float, float> currentcoords(floatposx, floatposy);
        rectanglecoords.push_back(currentcoords);
    }
}

void Pacman::Game::RenderPellet(int row, int col, sf::RenderWindow* windowptr, bool once) {
    float floatposy = row * 50;
    float floatposx = col * 50;
    sf::Color white(255, 255, 255);
    sf::CircleShape pellet(5);
    pellet.setFillColor(white);
    pellet.setOrigin(5,5);
    pellet.setPosition(floatposx + 25, floatposy + 25);
    windowptr->draw(pellet);
    if (once)
    {
        std::pair<float, float> currentcoords(floatposx + 25, floatposy + 25);
        pelletcoords.push_back(currentcoords);
    }
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
    std::pair<float, float> currentcoords;
}


void Pacman::Game::DrawMap(sf::RenderWindow* windowptr, bool once, std::shared_ptr<std::vector<std::string>> paczap) {
    int dotcounter = 0;
    for (int y = 0; y  < pacmanmap.size(); y++)
    {
        for (int x = 0; x < pacmanmap[0].size(); x++)
        {
            switch (paczap->at(y).at(x))
            {
                case '#':
                    RenderWall(y, x, windowptr, once);
                    break;
                case '.':
                    RenderPellet(y, x, windowptr, once);
                    break;
                case 'o':
                    RenderPowerPellet(y, x, windowptr);
                    break;
            }
        }
    }
}

Pacman::Game::Game(int score, int lives) {
    this->score = score;
    this->score = lives;
}
