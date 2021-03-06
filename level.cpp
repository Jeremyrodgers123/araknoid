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

using namespace std;

Level::Level(){};

Level::Level(string fileName, bool isGodMode) {
    field = Field(isGodMode);
    auto fieldSize = field.getShape().getSize();
    auto fieldPosition = field.getShape().getPosition();
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
    
    //get bar settings
    getline(ins, line);
    int barWidth = stoi(line);
    getline(ins, line);
    int barSpeed = stoi(line);
    auto barDimension = Vector2f(barWidth, BAR_HEIGHT);
    auto barPosition = Vector2f(fieldPosition.x + fieldSize.x/2 - barWidth/2, fieldPosition.y + fieldSize.y - 200);
    bar = Bar(barDimension, barPosition, barSpeed);
    
    //get ball settings
    getline(ins, line);
    int ballSpeed = stoi(line);
    auto ballPosition = barPosition;

    //ball position offset
    ball = Ball(ballPosition,ballSpeed);
    ball.centerWithBar(barWidth);
    
    while(getline(ins, line)) {
        currentBlockPosition.x = fieldPosition.x;
        for (char c : line) {
            int colorIndex = c - '0';
            blocks.push_back(Block(blockDimension, currentBlockPosition, colorIndex));
            currentBlockPosition.x += blockDimension.x;
        }
        currentBlockPosition.y += blockDimension.y;
    }
}

void Level::detectCollision(bool isGodeMode){
    ball.detectCollision(field, isGodeMode);
    ball.detectCollision(bar);
    for(Block &currentBlock : blocks){
        if (currentBlock.isActive){
            if(ball.detectCollision(currentBlock)){
                currentBlock.collision();
            }
        }
    }
};

bool Level::isComplete(){
    int remainingBlocks= std::count_if(blocks.begin(), blocks.end(),
    [](Block block){
        return block.isActive && block.isBreakable;
    });
    if (remainingBlocks <= 0){
        return true;
    }
    return false;
}
