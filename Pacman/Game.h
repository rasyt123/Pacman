//
// Created by rasyt on 8/27/2022.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
enum {PELLET, BIGPELLET, WALL, PACMAN};
namespace Pacman {
    class Game
    {
        public:
            Game(int score, int lives);
            void PacGameLoop();
            void DrawMap(sf::RenderWindow* windowptr);
            void RenderWall(int row, int col, sf::RenderWindow* windowptr);
            void RenderPellet(int row, int col, sf::RenderWindow* windowptr);
            void RenderPowerPellet(int row, int col, sf::RenderWindow* windowptr);

        private:
            int score;
            int lives;
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
    };
}



#endif //PACMAN_GAME_H
