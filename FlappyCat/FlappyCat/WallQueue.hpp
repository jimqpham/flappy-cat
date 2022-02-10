//
//  WallQueue.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Walls_hpp
#define Walls_hpp

#include <stdio.h>
#include "Wall.hpp"
#include <vector>

using namespace std;

class WallQueue {
    
public:
    vector <Wall> walls;
    int numWalls_;
    int gap_;
    
public:
    // Construct a WallQueue object, i.e. a queue of walls
    // Parameters: Number of walls, gap length in pixels between walls, and texture
    WallQueue (int numWalls, int gap, sf::Texture & texture);
    
    // Push all walls to the render window
    void draw (sf::RenderWindow & window);
    
    // Move (to the left if xSpeed < 0)
    void move (float xSpeed);
    
    // Return the wall vector in main.cpp so user can iterate through every wall in the queue
    // but does not allow changes to the vector
    vector<Wall> getWallVector() const {
        return walls;
    }
    
    // Calculate the user score = how many walls the cat has passed
    int calculateScore (Cat & theCat);
};

#endif /* Walls_hpp */

