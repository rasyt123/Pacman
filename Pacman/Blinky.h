//
// Created by rasyt on 8/27/2022.
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Pacman.h"

namespace Pacman {
    class Blinky
    {
        Blinky(float pacmanposy, float pacmanposx, int pacmantilerow, int pacmantilecol, int targettilerow, int targettilecol,
               sf::Texture* thetext, int ghosttilerow, int ghosttilecol);
        public:
            sf::RectangleShape blinky;
            void SetGreenTileIntersections();
            void SetYellowTileIntersections();
            void Update();

        sf::RectangleShape ghost;
    private:
            std::vector<std::string> pacmanmap = {
                    " ################### ",
                    " #........#........# ",
                    " #o##.###.#.###.##o# ",
                    " #.................# ",
                    " #.##.#.#####.#.##.# ",
                    " #....#...#...#....# ",
                    " ####.### # ###.#### ",
                    "    #.#   0   #.#    ",
                    "#####.# ##=## #.#####",
                    "     .  #123#  .     ",
                    "#####.# ##### #.#####",
                    "    #.#       #.#    ",
                    " ####.# ##### #.#### ",
                    " #........#........# ",
                    " #.##.###.#.###.##.# ",
                    " #o.#.....P.....#.o# ",
                    " ##.#.#.#####.#.#.## ",
                    " #....#...#...#....# ",
                    " #.######.#.######.# ",
                    " #.................# ",
                    " ################### "
            };
            //6,9 6,11 15,9 15, 11
            std::vector<std::pair<int, int>> greentileintersections;
            std::vector<std::pair<int,int>> yellowtileintersections;
            sf::Keyboard::Key currentdirection = sf::Keyboard::D;
            float speed = 2.5f;
            float pacmanposy;
            float pacmanposx;
            int pacmantilerow;
            int pacmantilecol;
            int targettilerow;
            int targettilecol;
            int ghosttilerow;
            int ghosttilecol;
            float posy;
            float posx;
            sf::Texture* thetext;

    };
}


#endif //PACMAN_BLINKY_H
