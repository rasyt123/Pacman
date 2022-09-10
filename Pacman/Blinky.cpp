//
// Created by rasyt on 8/27/2022.
//

#include "Blinky.h"


void Pacman::Blinky::SetGreenTileIntersections()
{
    int numberofdirections = 0;
    //6,9 6,11 15,9 15, 11
    for (int i = 0; i < pacmanmap.size(); i++)
    {
        for (int j = 0; j < pacmanmap[0].size(); j++)
        {
            std::pair<int,int> yellowcoords(i, j);
            if (pacmanmap[i][j] != '#')
            {
                if (std::find(yellowtileintersections.begin(), yellowtileintersections.end(), yellowcoords) == yellowtileintersections.end())
                {
                    if (pacmanmap[i-1][j] != '#')
                    {
                        numberofdirections += 1;
                    }
                    if (pacmanmap[i+1][j] != '#')
                    {
                        numberofdirections += 1;
                    }
                    if (pacmanmap[i][j-1] != '#')
                    {
                        numberofdirections += 1;
                    }
                    if (pacmanmap[i][j+1] != '#')
                    {

                        numberofdirections += 1;
                    }
                    if (numberofdirections > 2)
                    {
                        greentileintersections.push_back(yellowcoords);
                        numberofdirections = 0;
                    }
                }
            }
        }
    }

}

void Pacman::Blinky::SetYellowTileIntersections()
{
    //6,9 6,11 15,9 15, 11
    yellowtileintersections.push_back(std::make_pair(6,9));
    yellowtileintersections.push_back(std::make_pair(6,11));
    yellowtileintersections.push_back(std::make_pair(15,9));
    yellowtileintersections.push_back(std::make_pair(15,11));
}


int Pacman::Blinky::CalculateEuclidean(int startrow, int startcol, int endrow, int endcol)
{
    int rowdiff = abs(endrow - startrow);
    int coldiff = abs(endcol - startcol);
    int distancesquared = (rowdiff* rowdiff) + (coldiff * coldiff);
    return distancesquared;
}

std::pair<int,int> Pacman::Blinky::GrabTileCoords(float x, float y)
{
    for (int height = 0; height < pacmanmap.size(); height++)
    {
        for (int width = 0; width < pacmanmap[0].size(); width++)
        {
            float cellxpos = width * 50;
            float cellypos = height * 50;
            if (x > cellxpos and x < cellxpos + 50 and y > cellypos and y < cellypos + 50)
            {
                int row = height;
                int col = width;
               std::pair<int, int> tilecoords(row,col);
               return tilecoords;
            }
        }
    }
}



void Pacman::Blinky::Update() {
    sf::Vector2f movement(0.f, 0.f);

    //if im currently on a green tile, make the correct turn
        //set the current direction to be the choice made from calculating the euclidean distance (tileturn)
    //if im currently on a yellow tile
        //set


    //Take the current direction/position  and look ahead by one tile
            //iF the tile ahead of the current tile is a green tile
                //from green tile, check all directional tiles that arevalid that dont face the same direction
                    //for each one of these tiles, calculate euclidean distance,
                        //if the euclidean distances are the same, chose order of
                        //up > left > down
                        //choose tileturn to be whatever direction
            //if the tile ahead of the current tile is a wall and yoour at the center or greater
                    //check available directions and choose one in which you didn't just come from (no reversal)
                    //change current
            //if the tile ahead of the current tile is a yellow tile
                //Check surrounding valid directions but choose the same one you came from
            //otherwise:
                    //swtich statement on the
                    //keep moving in the same current direction
     //move into the current direction
    //Right after I make a movement, I call the animation class that updates the animation frame
    //







}

//Two modes: scatter and chase
//scatter for blinky means getting to the corner tile as the target
//chase for blinky means pacman's current position as a tile


Pacman::Blinky::Blinky(float pacmanposy, float pacmanposx, int pacmantilerow, int pacmantilecol, int targettilerow, int targettilecol,
                       sf::Texture *thetext, int ghosttilerow, int ghosttilecol) {
    this->pacmanposy = pacmanposy;
    this->pacmanposx = pacmanposx;
    this->pacmantilerow = pacmantilerow;
    this->pacmantilecol = pacmantilecol;
    this->targettilerow = targettilerow;
    this->targettilecol = targettilecol;
    this->ghosttilerow = ghosttilerow;
    this->ghosttilecol = ghosttilecol;
    this->posy = ghosttilerow * 50;
    this->posx = ghosttilecol * 50;
    this->thetext = thetext;
    ghost.setSize(sf::Vector2f(50, 50));
    //sf::Color yellow(255, 255, 0);
    //thepacman.setFillColor(yellow);
    ghost.setTexture(thetext);
    ghost.setOrigin(25, 25);
    ghost.setPosition(posx + 25, posy + 25);

}

