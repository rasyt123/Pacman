

#include "Game.h"
void Pacman::Game::PacGameLoop() {
    //each tile 50 pixels wide 50 pixels tall
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::RenderWindow pacwindow(sf::VideoMode(50 * pacmanmap[0].size(), 50 * pacmanmap.size()), "Pacman", sf::Style::Close | sf::Style::Titlebar);
    sf::Time TimePerFrame;
    TimePerFrame = sf::seconds(1.f / 60.f);
    Pacman pacman1(1, 2);
    pacwindow.setFramerateLimit(60);
    DrawMap(&pacwindow);
    pacman1.RenderPacman(&pacwindow);
    pacwindow.draw(pacman1.thepacman);
    pacwindow.display();
    while (pacwindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            pacwindow.clear();
            DrawMap(&pacwindow);
            pacman1.ProcessPacmanMovement(&pacwindow, TimePerFrame);
            pacwindow.draw(pacman1.thepacman);
            pacwindow.display();
        }
    }
}


bool Pacman::Game::CollisonCheck(Pacman& paccolide) {
    bool topleftcolli = false;
    bool toprightcolli = false;
    bool bottomleftcolli = false;
    bool bottomrightcolli = false;
    for (std::pair<float, float>& wall : rectanglecoords)
    {
        float wallxleft = wall.first;
        float wallxright = wall.first + 50;
        float wallytop = wall.second;
        float wallybottom = wall.second + 50;
        for (std::vector<float>& rectangle : paccolide.all4rects)
        {
            //check for an intersection in both planes
            //both  projections must be intersecting for there to be a collision
            if (((wallybottom >= rectangle[0] and wallybottom <= rectangle[1]) or
            (wallytop <= rectangle[1] and wallytop >= rectangle[0]))
             and ((rectangle[2] <= wallxright and rectangle[2] >= wallxleft)
             or (wallxleft <= rectangle[3] and wallxleft >= rectangle[2])))
            {
                return true;
            }
        }
    }
    return false;
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
    std::pair<float, float> currentcoords(floatposx, floatposy);
    rectanglecoords.push_back(currentcoords);
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
    std::pair<float, float> currentcoords;
    rectanglecoords.push_back(currentcoords);
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
    rectanglecoords.push_back(currentcoords);
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

Pacman::Game::Game(int score, int lives) {
    this->score = score;
    this->score = lives;
}

