//
//  Grass.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Grass_hpp
#define Grass_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace std;

class Grass {
    
private:
    
    // the rectangle that contains the grasss picture
    sf::Sprite grassRec_;
    
    int width, height; // width and height of the glass block in pixels
    
    // for determining if the cat hits the grass
    friend class Cat;
    
public:
    
    // constructor for the grass block
    Grass (int grassHeight, int scrWidth, int scrHeight, sf::Texture & grassTexture);
    
    // push the grass bloc to the render window
    void draw (sf::RenderWindow & window);
    
};

#endif /* Grass_hpp */

