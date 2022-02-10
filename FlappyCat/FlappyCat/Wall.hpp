//
//  Wall.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Cat.hpp"

class Wall {
    
private:
    
    sf::Sprite upperWall_, lowerWall_;
    float upperHeight_, lowerHeight_, width_;
    int xIniPos_;
    friend class Cat;
    
public:
    
    // Construct a wall with a hole of which the width is a fixed percentage of wall height
    // the hole position on the wall is random
    Wall ( int screenHeight, int xIniPos, int width, sf::Texture & texture );
    
    // Constructor that allows modifications of the hole in the wall
    // For testing purposes only
    Wall (int screenHeight, int xIniPos, int width, float upperHeightPct, sf::Texture & texture );
    
    // Push the objects to the render window
    void draw (sf::RenderWindow & window);
    
    void setXPosition(int xPos);
    
    int getXPosition();
    
    // set the walls' moving speed
    // the walls should be moving along the x-axis (i.e. horizontally) only
    // so we only need the xSpeed parameter
    void move (float xSpeed);
    
    // If the wall passed the cat (to the left of the cat), return true
    // This helps calculate the score later on
    bool isPastCat (Cat theCat);
    
    // When the cat hits the wall or ground or ceiling, return true as the cue to end the game

    bool isCollided (Cat & theCat);

};

#endif /* Wall_hpp */

