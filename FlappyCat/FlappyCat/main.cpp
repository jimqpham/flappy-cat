//
//  main.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/20/21.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Cat.hpp"
#include "Wall.hpp"
#include "WallQueue.hpp"
#include "HelperFunction.hpp"
#include "TestFunctions.hpp"
#include "Grass.hpp"

using namespace std;

int main() {
    
    // Set up the render window
    int screenWidth = 1600;
    int screenHeight = 1200;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Flappy Cat");
    window.setFramerateLimit(60);
    
    
    // Load the texture (image) for the wall, grass and cat
    sf::Texture wallTexture;
    wallTexture.loadFromFile("brick_texture.png");
    wallTexture.setRepeated(true);
    
    sf::Texture grassTexture;
    grassTexture.loadFromFile("grass_texture.png");
    grassTexture.setRepeated(true);
    
    sf::Texture catTexture;
    catTexture.loadFromFile("cat_texture.png");
    
    
    // Constructor for the cat
    Cat cat{catTexture};
    
    // Constructor for the walls
    int numWalls = 100; // 100 walls
    int wallGap = 600; // 600 pixels between walls
    WallQueue walls (numWalls, wallGap, wallTexture);
    
    // Constructor for the grass
    int grassHeight = 100; // pixels
    Grass grass {grassHeight, screenWidth, screenHeight, grassTexture};
    
    // Game flow variable
    // Create a variable to track if the game is over
    bool isGameOver = false;
    
    // Create a variable to track if the user pauses the game
    bool isPaused = false;
    
    // Create a variable to track if the game starts
    // If not, prompt the user to hit some key to start
    bool hasStarted = false;
    
    // Create a variable to track the walls' moving speed
    float xSpeed = -3;
    
    // Create a variable to track the darkness/day-night feature
    float darkness = 0;
    bool increaseDarkness = false;
    float deltaDarkness = 0.1; // speed of changing the background color
    
    // Do tests before starting the game
    test();
    
    // Start the game
    while (window.isOpen())
    {
        // Create a variable to track user's core that is updated every frame
        int score = walls.calculateScore(cat);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // press Escape to exit
                window.close();
            }
        }
        
        if (!hasStarted) { // If the game hasn't started
            
            // Display non-moving objects in the background
            drawAll(cat, walls, grass, darkness, window);

            // Print out the message box to prompt user hit Enter
            string  message = "PRESS ENTER\nTO START";
            printMessageWithBox(message, sf::Color::Red, screenWidth, screenHeight, window);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                hasStarted = true;
            }
            
        }
        
        else if (isPaused) { // If the game is paused
            
            // Display objects in the background
            drawAll(cat, walls, grass, darkness, window);
            
            // Print out the message box
            string  message = "PAUSED! \n\nPRESS C\nTO CONTINUE";
            printMessageWithBox(message, sf::Color::Red, screenWidth, screenHeight, window);
            
            window.display();
            
            // If the user hits [C]ontinue, continue the game
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                isPaused = false;
            }
            
        }
        
        else if (isGameOver) { // Do these when the game is over
            
            // Display objects in the background
            drawAll(cat, walls, grass, darkness, window);
            
            // Print out the game over message box
            string  message = "GAME OVER!\n\nSCORE: " + to_string(score) + "\n\nPRESS ENTER\nTO RESTART";
            printMessageWithBox(message, sf::Color::Red, screenWidth, screenHeight, window);
            
            window.display();
            
            // If the user hits Enter, restart the game
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                main();
            }
            
            
        }
        
        else {
            
            // If no key is pressed, the cat drops to the ground
            // and the walls move to the left by 3 pixels/frame
            cat.drop();
            walls.move(xSpeed);
            xSpeed -= 0.003; // walls moving faster as we go
            
            // If the Space key is pressed, the cat jumps by 7 pixels/frame
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                cat.jump(7); // bigger number means cat jumping higher
            }
            
            // If the user hits [P]ause, pause the game
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                isPaused = true;
            }
            
            // The game is over when the cat hits the ceiling/ground
            if (cat.hitGrass(grass) || cat.hitCeiling()) {
                isGameOver = true;
            }
            for (Wall & w: walls.getWallVector()) {
                if (w.isCollided(cat)) {
                    isGameOver = true;
                }
            }
            
            // Manage the darkness in the background
            if (darkness >= 100) {
                increaseDarkness = false;
                darkness-=deltaDarkness;
            } else if (darkness <= 0) {
                increaseDarkness = true;
                darkness+=deltaDarkness;
            } else {
                if (increaseDarkness)
                    darkness+=deltaDarkness;
                else
                    darkness-=deltaDarkness;
            }
            
            // Display objects in the background
            drawAll(cat, walls, grass, darkness, window);
            
            // Print out the score at the lower right of the screen
            string scoreMessage = "SCORE: " + to_string(score);
            printMessage(scoreMessage, sf::Color::White, 25, screenWidth - 200, screenHeight - 60, window);
            
            // Print out the pause instruction at the lower left of the screen
            string pauseMessage = "PRESS P TO PAUSE";
            printMessage(pauseMessage, sf::Color::White, 25, 100, screenHeight - 60, window);
            
            // Display
            window.display();
            
        }
    }
}
