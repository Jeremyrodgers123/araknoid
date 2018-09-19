//
//  level.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include <iostream>
#include <fstream>
#include <string>
#include "level.hpp"
#include "block.hpp"
#include "ball.hpp"
#include "bar.hpp"

const int BLOCKS_PER_ROW = 13;
const int BLOCKS_PER_COLUMN = 10;
const int BLOCK_HEIGHT = 25;

const int BAR_HEIGHT = 20;

using namespace std;
Level::Level(string fileName, int& _currentLives) {
    field = Field();
    auto fieldTopPosition = field.getShape().getGlobalBounds().top;
    auto fieldHeight = field.getShape().getGlobalBounds().height;
    auto fieldBottomPosition = fieldTopPosition + fieldHeight;
    auto fieldLeftPosition = field.getShape().getGlobalBounds().left;
    auto fieldWidth = field.getShape().getGlobalBounds().width;
    auto fieldRightPosition = fieldLeftPosition + fieldWidth;
    currentLives = _currentLives;
    auto fieldSize = field.getShape().getSize();
    auto fieldPosition = field.getShape().getPosition();
                               
    
    blocks = vector<Block>(BLOCKS_PER_ROW * BLOCKS_PER_COLUMN);
    auto blockDimension = Vector2f(fieldSize.x / BLOCKS_PER_ROW, BLOCK_HEIGHT);
    auto currentBlockPosition = fieldPosition;
    ifstream ins(fileName);
    if (!ins) {
        cout << fileName << " not found." << endl;
        exit(1);
    }
    string line;
    
    //get name
    getline(ins, name);
    
    //get author
    getline(ins, author);
    
    //get bar settingsd
    getline(ins, line);
    int barWidth = stoi(line);
    getline(ins, line);
    int barSpeed = stoi(line);
    auto barDimension = Vector2f(barWidth, BAR_HEIGHT);
    auto barPosition = Vector2f(fieldPosition.x + fieldSize.x/2 - barWidth/2, fieldBottomPosition - 200);
    bar = Bar(barDimension, barPosition, barSpeed);
    
    //get ball settings
    getline(ins, line);
    int ballSpeed = stoi(line);
    auto ballPosition = barPosition;
    ball = Ball(ballPosition, ballSpeed);
    
    //get isGodMode
    getline(ins, line);
    isGodMode = stoi(line);
    
    auto rowNum = 0;
    while(getline(ins, line)) {
        currentBlockPosition.x = fieldPosition.x;
        auto colNum = 0;
        for (char c : line) {
            int colorIndex = c - '0';
            blocks[rowNum * BLOCKS_PER_ROW + colNum] = Block(blockDimension, currentBlockPosition, colorIndex);
            currentBlockPosition.x += blockDimension.x;
            colNum++;
        }
        currentBlockPosition.y += blockDimension.y;
        rowNum++;;
    }
}

void Level::draw(RenderWindow& window) {
    window.draw(field.getShape());
    window.draw(bar.getShape());
    for (auto block : blocks) {
        if (block.isActive) {
            window.draw(block.getShape());
        }
    }
    ball.move();
    detectCollision();
    if(!ball.isInbounds){
        currentLives -= 1;
        float speed = ball.getSpeed();
        Vector2f position = bar.getPosition();
        ball = Ball(position, speed);
    }
    window.draw(ball.getShape());
}

void Level::detectCollision(){
    ball.detectCollision(field);
    ball.detectCollision(bar);
    for(Block &currentBlock : blocks){
        if (currentBlock.isActive){
            if(ball.detectCollision(currentBlock)){
                cout << "collision detected" << endl;
                currentBlock.collision();
            }
        }
    }
};
