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

class Level {
private:
    string name;
    string author;
    vector<Block> blocks;
    Ball ball;
public:
    Bar bar;
    Field field;
    bool isGodMode;
    
    Level(string fileName);
    
    void draw(RenderWindow& window);
    void detectCollision();
    string getName() {return name;};
    string getAuthor() {return author;};
};

#endif /* level_hpp */
