//
//  TestFunctions.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/24/21.
//

#ifndef TestFunctions_hpp
#define TestFunctions_hpp

#include <stdio.h>
#include <iostream>
#include "Cat.hpp"
#include "Wall.hpp"

// Test if the cat collides with the wall
void testWallCollision ();

// Test if the cat collides with the grass
void testGrassCollision ();

// Test if the cat collides with the ceiling
void testCeilingCollision ();

// Wrapper of all three tests above
void test ();

#endif /* TestFunctions_hpp */
