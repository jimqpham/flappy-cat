//
//  Grass.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "Grass.hpp"
#include <SFML/Graphics.hpp>

// constructor for the grass block
Grass::Grass (int grassHeight, int scrWidth, int scrHeight, sf::Texture & grassTexture) {
    
    // set texture for the grass
    // the texture is passed via the grassTexture variable
    grassRec_.setTexture(grassTexture);
    
    // set the size of the grass block
    // in this case, grass width = screen width (the grass running from left edge to right edge of the screen)
    // grass height is set using the grassHeight parameter
    grassRec_.setTextureRect(sf::IntRect(0, 0, scrWidth, grassHeight));

    // set the position of the grass at the bottom of the screen
    // the grass block starts at the left edge, hence its x position = 0
    grassRec_.setPosition(0, scrHeight - grassHeight);
    
    
}

// push the grass bloc to the render window
void Grass::draw (sf::RenderWindow & window) {
    
    window.draw(grassRec_);
    
}
