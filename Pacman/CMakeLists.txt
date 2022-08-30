cmake_minimum_required(VERSION 3.21)
project(Pacman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pacman main.cpp Pacman.cpp Pacman.h Ghost.cpp Ghost.h Game.cpp Game.h Blinky.cpp Blinky.h Plinky.cpp Plinky.h Inky.cpp Inky.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Pacman sfml-system sfml-window sfml-graphics sfml-audio)