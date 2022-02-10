//
//  TestFunctions.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/24/21.
//

#include "TestFunctions.hpp"
#include <stdio.h>
#include <iostream>
#include "Cat.hpp"
#include "Wall.hpp"

void testWallCollision () {

    sf::Texture catTexture, wallTexture;
    Cat theCat(catTexture);
    Wall theWall(1200, 100, 100, 75, wallTexture);
    
    // Set the cat and the wall at the same position - guarantee crashing
    theCat.setXPosition(100);
    theCat.setYPosition(0);
    theWall.setXPosition(100);

    if (!theWall.isCollided(theCat)) {
        std::cout << "Wall collision test failed.";
        exit (1);
    }
    
    // Set the cat and the wall at different position - no crashing
    theCat.setXPosition(100);
    theCat.setYPosition(0);
    theWall.setXPosition(200);

    if (theWall.isCollided(theCat)) {
        std::cout << "Wall collision test failed.";
        exit (1);
    }
}

void testGrassCollision () {

    sf::Texture catTexture, grassTexture;
    Cat theCat(catTexture);
    Grass theGrass (50, 1600, 1200, grassTexture);

    // Set the cat "beneath" the grass surface - hit
    theCat.setXPosition(100);
    theCat.setYPosition(1175);

    if (!theCat.hitGrass(theGrass)) {
        std::cout << "Grass collision test 1 failed.";
        exit (1);
    }
    
    // Set the cat above the grass surface - no hit
    theCat.setXPosition(100);
    theCat.setYPosition(100);

    if (theCat.hitGrass(theGrass)) {
        std::cout << "Grass collision test 2 failed.";
        exit (1);
    }

}

void testCeilingCollision () {
    
    sf::Texture catTexture, grassTexture;
    Cat theCat(catTexture);
    
    // Set the cat above the ceiling - hit
    theCat.setYPosition(-100);
    
    if (!theCat.hitCeiling()) {
        std::cout << "Ceiling collision test failed.";
        exit (1);
    }
    
    // Set the cat under the ceiling - no hit
    theCat.setYPosition(100);

    if (theCat.hitCeiling()) {
        std::cout << "Ceiling collision test failed.";
        exit (1);
    }
}

void test () {
    
    testWallCollision();
    testGrassCollision();
    testCeilingCollision();
    
}
