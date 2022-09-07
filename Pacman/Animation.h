//
// Created by rasyt on 9/7/2022.
//

#ifndef PACMAN_ANIMATION_H
#define PACMAN_ANIMATION_H
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

    class Animation
    {
    public:
            Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
            ~Animation();
            void Update(int row, float deltaTime);
    public:
        sf::IntRect uvRect;
    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;

        float totalTime;
        float switchTime;

    };




#endif //PACMAN_ANIMATION_H
