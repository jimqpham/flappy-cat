//
//  WallQueue.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "WallQueue.hpp"
#include "Wall.hpp"
#include <vector>

// Construct a WallQueue object, i.e. a queue of walls
// Parameters: Number of walls, gap length in pixels between walls, and texture
WallQueue::WallQueue (int numWalls, int gap, sf::Texture & texture) {
    
    gap_ = gap;
    numWalls_ = numWalls;
    
    int screenHeight = 1200;
    int firstWallXPosition = 500; // x position of the first wall when the game starts
    int width = 100; // wall width in pixels
    
    // Generate and push each wall into the queue
    // Each wall should be 450 pixels (gap length) after its preceding wall
    for (int i = 0; i < numWalls_; i++) {
        
        Wall newWall{screenHeight, firstWallXPosition + i * gap_, width, texture};
        walls.push_back (std::move(newWall));
        // We're using std::move to push the reference of the wall to the queue
        // Without this, only a copy of the wall gets pushed
        // hence walls losing their texture in the queue
        
    }
    
}

// Push all walls to the render window
void WallQueue::draw (sf::RenderWindow & window) {
//for each loop
    for (Wall & wall: walls) {
        wall.draw(window);
    }
    
}

// Move (to the left if xSpeed < 0)
void WallQueue::move (float xSpeed) {
    for (int i = 0; i < numWalls_; i++) {
        walls[i].move(xSpeed);
    }
}

// Calculate the user score = how many walls the cat has passed
int WallQueue::calculateScore (Cat & theCat) {
    
    int score = 0;

    // Examine each wall in the queue
    for (Wall & w: walls) {
        // If the cat has passed through another wall, increment the score
        if (w.isPastCat(theCat)) {
            score++;
        }
        
    }
    
    return score;
    
}
