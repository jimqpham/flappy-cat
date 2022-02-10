//
//  HelperFunction.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "HelperFunction.hpp"
#include "WallQueue.hpp"
#include "Cat.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>

// Print text to the game screen (e.g. the score at the lower right)
void printMessage (std::string message, sf::Color fontColor, int fontSize, int xPos, int yPos, sf::RenderWindow & window) {
    
    // displaying the message
    sf::Text text;

    // select the font
    sf::Font font;
    std::string fontPath = "RetroGaming.ttf";
    font.loadFromFile(fontPath);
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(message);

    // set the character size
    text.setCharacterSize(fontSize); // in pixels, not points!

    // set the color
    text.setFillColor(fontColor);

    // set the text style
    text.setStyle(sf::Text::Bold);
    
    text.setPosition(xPos, yPos);

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);
}


// Print important text message with box (e.g. welcome screen, game over screen, pause screen)
void printMessageWithBox (std::string message, sf::Color fontColor, int scrWidth, int scrHeight, sf::RenderWindow & window) {
    
    // create a translucent layer over the screen
    sf::RectangleShape translucentLayer;
    translucentLayer.setFillColor(sf::Color(255, 255, 255, 200));
    translucentLayer.setOutlineColor(sf::Color::White);
    translucentLayer.setSize(sf::Vector2<float>(scrWidth, scrHeight));
    translucentLayer.setPosition(0, 0);
    window.draw(translucentLayer);
    
    // create the message box
    sf::RectangleShape messBox;
    messBox.setFillColor(sf::Color(255, 255, 255));
    messBox.setOutlineColor(sf::Color::Red);
    messBox.setOutlineThickness(20);
    messBox.setSize(sf::Vector2<float>(scrWidth/3, scrHeight/3));
    messBox.setPosition(scrWidth/3, scrHeight/3);
    window.draw(messBox);
    
    int fontSize = 40;
    int xPos = scrWidth/3 + 50; // 50 is the padding between text & box edge
    int yPos = scrHeight/3 + 50; // 50 is the padding between text & box edge
    
    printMessage(message, fontColor, fontSize, xPos, yPos, window);
    
}

void drawAll (Cat &theCat, WallQueue &walls, Grass &grass, float darkness, sf::RenderWindow & window) {
    
    sf::Color bgColor = sf::Color(104 - darkness, 156 - darkness, 216 - darkness, 250); // set background to blue/darkblue depending on the darkness parameter
    window.clear(bgColor);
    theCat.draw(window);
    walls.draw(window);
    grass.draw(window);
    
}

