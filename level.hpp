//
//  level.hpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#ifndef level_hpp
#define level_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "ball.hpp"
#include "bar.hpp"
#include "field.hpp"

using namespace std;

const int BLOCKS_PER_ROW = 13;
const int BLOCK_HEIGHT = 25;
const int BAR_HEIGHT = 20;

class Level {
private:
    string name;
    string author;
public:
    Bar bar;
    Ball ball;
    vector<Block> blocks;
    Field field;
    Level();
    Level(string fileName, bool isGodMode);
    bool isComplete();
    void draw(RenderWindow& window);
    void detectCollision(bool isGodeMode);
    string getName() {return name;};
    string getAuthor() {return author;};
};

#endif /* level_hpp */
