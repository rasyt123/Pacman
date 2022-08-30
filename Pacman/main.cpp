#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Pacman::Game pacman(1, 1);
    pacman.PacGameLoop();
    return 0;
}
