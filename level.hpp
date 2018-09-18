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

using namespace std;

class Level {
private:
    vector<Block> blocks;
    Ball ball;
public:
    Bar bar;
    Level(int windowHeight, int level);
    void draw(RenderWindow& window);
};

#endif /* level_hpp */
