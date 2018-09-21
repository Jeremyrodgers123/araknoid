//
//  game.cpp
//  arkanoid
//
//  Created by Adam Quintana on 9/18/18.
//

#include <vector>
#include <iostream>
#include "game.hpp"
#include "level.hpp"

using namespace std;

Game::Game() {}

Game::Game(int _numLives) {
    numLives = _numLives;
    for (string levelName : LEVEL_NAMES) {
        levels.push_back(Level(levelName, getGodMode()));
    }
    // Declare and load a font
    sf::Font font;
    font.loadFromFile("ArialBlack.ttf");
    fontType = font;
}

void Game::draw(RenderWindow& window, int levelIndex, bool isGodeMode) {
    // Create text
    sf::Text text("Lives: ", fontType, 30);
    text.setStyle(sf::Text::Bold);
    text.setString("Lives: "  + to_string(numLives));
   
    Level &currentLevel = levels[levelIndex];
    window.draw(currentLevel.field.getShape());
    window.draw(currentLevel.bar.getShape());
    for (auto block : currentLevel.blocks) {
        if (block.isActive) {
            window.draw(block.getShape());
        }
    }
    currentLevel.ball.move();
    currentLevel.detectCollision(isGodeMode);
    if(!currentLevel.ball.isInbounds){
        numLives -= 1;
        float speed = currentLevel.ball.getSpeed();
        Vector2f position = currentLevel.bar.getPosition();
        currentLevel.ball = Ball(position, speed);
        int barWidth = currentLevel.bar.getShape().getSize().x;
        currentLevel.ball.centerWithBar(barWidth);
    }
    window.draw(currentLevel.ball.getShape());
    window.draw(text);
}

void Game::initGodMode(Level &currentLevel){
    godMode = true;
    currentLevel.field = Field(getGodMode());
    auto barPosition = currentLevel.bar.getPosition();
    auto barSize = currentLevel.bar.getShape().getSize();
    auto ballVelocity = currentLevel.ball.getVelocity();
    currentLevel.bar = Bar(barSize, barPosition, 100);
    currentLevel.ball.setVelocity(ballVelocity.x *= 1.3, ballVelocity.y *= 1.1);
}


