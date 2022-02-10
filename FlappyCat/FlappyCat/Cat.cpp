//
//  Cat.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "Cat.hpp"
#include <SFML/Graphics.hpp>
#include "Grass.hpp"

// Constructor
Cat::Cat (sf::Texture & catTexture) {
    
    catRec_.setTexture(catTexture);
    catRec_.setTextureRect(sf::IntRect(0, 0, 70, 55)); // texture image size: 30x23 pixels
    
    catRec_.setPosition(xPos_, yPos_);
 
}

// drop the cat to the ground if no key is pressed
void Cat::drop () {
    
    yPos_ += velo_;
    velo_ += accel_; // add acceleration to velocity
    catRec_.setPosition(xPos_, yPos_);
    
}

// jump the cat when Space is pressed
void Cat::jump (int jumpDist) {
    
    velo_ = -jumpDist ;
    catRec_.setPosition(xPos_, yPos_);
    
}

// Did the cat hit the ceiling (top of the screen)?
bool Cat::hitCeiling () {
    
    return yPos_ <= 0;
    
}

// Did the cat hit the ground/grass?
bool Cat::hitGrass (const Grass & grass) {
    
    // Get the rectangle bound of the cat and the grass
    sf::FloatRect catBound = catRec_.getGlobalBounds();
    sf::FloatRect grassBound = grass.grassRec_.getGlobalBounds();
    
    // And return if the bounds intersect
    return (catBound.intersects(grassBound));
}


// Print out the cat to the display
void Cat::draw (sf::RenderWindow & window) {
    
    window.draw(catRec_);
    
}

// Get the horizontal coordinate
float Cat::getXPosition() {
    return xPos_;
}

// Set the horizontal coordinate - for testing
void Cat::setXPosition(int xPos) {
    xPos_ = xPos;
    catRec_.setPosition(xPos_, yPos_);
}

// Get the vertical coordinate
float Cat::getYPosition() {
    return yPos_;
}

// Set the vertical coordinate - for testing
void Cat::setYPosition(int yPos) {
    yPos_ = yPos;
    catRec_.setPosition(xPos_, yPos_);
}
