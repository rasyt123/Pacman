//
// Created by rasyt on 9/7/2022.
//

#include "Animation.h"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, int col) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = col;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}


void Animation::Update(int row,int col, int colstop, float deltaTime)
{
    currentImage.y = row;
    currentImage.x = col;
   totalTime += deltaTime;
    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= colstop)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;

}