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
#include "Animation.h"
enum {PELLET, BIGPELLET, WALL, PACMAN};
namespace Pacman {
    class Game
    {
        public:
            Game(int score, int lives);
            void PacGameLoop();
            void DrawMap(sf::RenderWindow* windowptr, bool once, std::shared_ptr<std::vector<std::string>> paczap);
            void RenderWall(int row, int col, sf::RenderWindow* windowptr, bool once);
            void RenderPellet(int row, int col, sf::RenderWindow* windowptr, bool once);
            void RenderPowerPellet(int row, int col, sf::RenderWindow* windowptr);
            bool CollisonCheck(Pacman& paccolide);

        private:
            int score;
            int lives;
            std::vector<std::pair<float, float>> rectanglecoords;
            std::vector<std::pair<float, float>> pelletcoords;
            std::vector<std::pair<float, float>> powerpelletcoords;
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
