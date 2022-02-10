//
//  Cat.hpp
//  FlappyCat
//

#ifndef Cat_hpp
#define Cat_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Grass.hpp"

class Cat {
    
private:
    
    // catRec_ is the rectangle containing the texture/image of the cat
    sf::Sprite catRec_;
    
    // default value of the cat movement
    float velo_ = 0.2;  // velocity
    float accel_ = 0.2; // acceleration factor
    float xPos_ = 100;  // initial x position - this won't be changed
    float yPos_ = 100;  // initial y position
    
    // Add Wall class as friend to handle collision later
    friend class Wall;
    
    
public:

    // Constructor
    Cat (sf::Texture & catTexture);
    
    // drop the cat to the ground if no key is pressed
    void drop ();
    
    // jump the cat when Space is pressed
    void jump (int jumpDist);
    
    // Did the cat hit the ceiling (top of the screen)?
    bool hitCeiling ();
    
    // Did the cat hit the ground/grass?
    bool hitGrass (const Grass & grass);
    
    
    // Print out the cat to the display
    void draw (sf::RenderWindow & window);
    
    // Get the horizontal coordinate
    float getXPosition();
    
    // Set the horizontal coordinate
    void setXPosition(int xPos);
    
    // Get the vertical coordinate
    float getYPosition();
    
    // Set the vertical coordinate
    void setYPosition(int yPos);
    
};

#endif /* Cat_hpp */
