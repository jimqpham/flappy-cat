//
//  HelperFunction.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef HelperFunction_hpp
#define HelperFunction_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "WallQueue.hpp"
#include "Cat.hpp"
#include <string>
#include <iostream>

// Print text to the game screen (e.g. the score at the lower right)
void printMessage (std::string message, sf::Color fontColor, int fontSize, int xPos, int yPos, sf::RenderWindow & window);

// Print important text message with box (e.g. welcome screen, game over screen, pause screen)
void printMessageWithBox (std::string message, sf::Color fontColor, int scrWidth, int scrHeight, sf::RenderWindow & window);

// Draw (Push to render window) all (cat, grass, walls, background color)
void drawAll (Cat &theCat, WallQueue &walls, Grass &grass, float darkness, sf::RenderWindow & window);

#endif /* HelperFunction_hpp */
