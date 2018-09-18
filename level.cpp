//
//  level.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

//#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "block.hpp"
#include "ball.hpp"
#include "bar.hpp"
#include <iostream>

const int BLOCKS_PER_ROW = 13;
const int BLOCKS_PER_COLUMN = 6;
const int BLOCK_HEIGHT = 25;
const int BUFFER = 20;
const vector<int> BAR_WIDTHS_PER_LEVEL = vector<int> {100, 75, 50, 25};
const vector<int> BALL_SPEEDS_PER_LEVEL = vector<int> {10, 20, 30, 40};

using namespace std;

vector<Block> buildLevelOne(int windowWidth) {
    auto blocks = vector<Block>(BLOCKS_PER_ROW * BLOCKS_PER_COLUMN);
    auto blockWidth = (windowWidth - BUFFER) / BLOCKS_PER_ROW;
    auto blockHeight = BLOCK_HEIGHT;
    //int colorIndex = rand() % Block::BREAKABLE_COLORS.size();
    int colorIndex = 0;
    auto yPosition = BUFFER;
    for (int row = 0; row < BLOCKS_PER_COLUMN; row++) {
        auto xPosition = BUFFER;
        for (int col = 0; col < BLOCKS_PER_ROW; col++) {
            auto dimension = Vector2f(blockWidth, blockHeight);
            auto position = Vector2f(xPosition, yPosition);
            blocks[row * BLOCKS_PER_ROW + col] = Block(dimension, position, colorIndex, true, true);
            xPosition += blockWidth;
        }
        yPosition += blockHeight;
        colorIndex++;
    }
    return blocks;
}

Level::Level(int windowHeight, int level) {
    bar = Bar(BAR_WIDTHS_PER_LEVEL[level - 1]);
    ball = Ball();
    switch (level) {
        case 1:
            blocks = buildLevelOne(windowHeight);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void Level::draw(RenderWindow& window) {
    window.draw(bar.getShape());
    for (auto block : blocks) {
        if (block.isActive) {
            window.draw(block.getShape());
        }
    }
    ball.move();
    detectCollision();
    window.draw(ball.getShape());
}
void Level::detectCollision(){
    for(Block &currentBlock : blocks){
        if (currentBlock.isActive){
            if(ball.detectCollision(currentBlock)){
                cout << "collision detected" << endl;
                currentBlock.collision();
            }
        }
    }
};
