//
//  Wall.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "Wall.hpp"

#include <SFML/Graphics.hpp>
#include "Cat.hpp"

// Construct a wall with a hole of which the width is a fixed percentage of the wall height
// the hole position on the wall is random
Wall::Wall (int screenHeight, int xIniPos, int width, sf::Texture & texture ) {
    
    xIniPos_ = xIniPos;
    width_ = width;
    
    // As each wall has a hole in it, the hole divides the wall into 2 parts: the upper wall and the lower wall
    // We hardcoded the size of the hole = 25% screen height
    // Therefore the height of the upper and lower wall should add up to 75% screen height
    // The height of either of them should be generated randomly, as long as the sum of two heights = 75% screen height
    
    // To randomly generate the heights, we do as follows:
    // Generate a random number from 5 to 70 and divide it by 100
    // This number (upper height percentage) represents the height of the upper wall as a percentage of the total screen height, which means the upper wall can be from 5% to 70% of the screen height. We have the hole = 25% screen height, so the lower wall should be 5% to 70% of the screen height as well
    float upperHeightPct = ((float) (5 + rand() % 66))/100;
    
    // From the percentage, calculate the actual heights in pixels
    upperHeight_ = screenHeight*upperHeightPct;
    lowerHeight_ = screenHeight*(1 - upperHeightPct - 0.25);
    
    //set the walls' texture and size
    upperWall_.setTexture(texture);
    upperWall_.setTextureRect(sf::IntRect(0, 0, width, upperHeight_));
    lowerWall_.setTexture(texture);
    lowerWall_.setTextureRect(sf::IntRect(0, 0, width, lowerHeight_));
    
    //set the walls' x and y position
    upperWall_.setPosition(xIniPos_, 0);
    lowerWall_.setPosition(xIniPos_, screenHeight - lowerHeight_);
}

// Constructor that allows modifications of the hole in the wall
// For testing purposes only
Wall::Wall (int screenHeight, int xIniPos, int width, float upperHeightPct, sf::Texture & texture ) {
    
    xIniPos_ = xIniPos;
    width_ = width;
    
    // From the percentage, calculate the actual heights in pixels
    upperHeight_ = screenHeight*upperHeightPct;
    lowerHeight_ = screenHeight*(1 - upperHeightPct - 0.25);
    
    //set the walls' texture and size
    upperWall_.setTexture(texture);
    upperWall_.setTextureRect(sf::IntRect(0, 0, width, upperHeight_));
    lowerWall_.setTexture(texture);
    lowerWall_.setTextureRect(sf::IntRect(0, 0, width, lowerHeight_));
    
    //set the walls' x and y position
    upperWall_.setPosition(xIniPos_, 0);
    lowerWall_.setPosition(xIniPos_, screenHeight - lowerHeight_);
}

// Push the objects to the render window
void Wall::draw (sf::RenderWindow & window) {
    
    window.draw(std::move(upperWall_));
    window.draw(std::move(lowerWall_));
    
}

// Set wall's x position
void Wall::setXPosition(int xPos) {
    
    upperWall_.setPosition(xPos, 0);
    lowerWall_.setPosition(xPos, 1200 - lowerHeight_);
    
}

// get wall's x position
int Wall::getXPosition() {
    
    return upperWall_.getPosition().x;
    
}

// set the walls' moving speed
// the walls should be moving along the x-axis (i.e. horizontally) only
// so we only need the xSpeed parameter
void Wall::move (float xSpeed) {
    
    upperWall_.move(xSpeed, 0);
    lowerWall_.move(xSpeed, 0);
    
}

// If the wall passed the cat (to the left of the cat), return true
// This helps calculate the score later on
bool Wall::isPastCat (Cat theCat) {
    
    return getXPosition() < theCat.getXPosition() - width_;
    
}

// When the cat hits the wall or ground or ceiling, return true as the cue to end the game
bool Wall::isCollided (Cat & theCat) {
    
    sf::FloatRect catBound = theCat.catRec_.getGlobalBounds();
    sf::FloatRect upperWallBound = upperWall_.getGlobalBounds();
    sf::FloatRect lowerWallBound = lowerWall_.getGlobalBounds();
    
    return (catBound.intersects(upperWallBound) || catBound.intersects(lowerWallBound));
    
}
