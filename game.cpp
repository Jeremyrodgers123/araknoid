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
}

void Game::draw(RenderWindow& window, int levelIndex, bool isGodeMode) {
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
    }
    window.draw(currentLevel.ball.getShape());
}


