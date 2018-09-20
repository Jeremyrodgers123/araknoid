//
//  game.hpp
//  arkanoid
//
//  Created by Adam Quintana on 9/18/18.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <vector>
#include "level.hpp"
const vector<string> LEVEL_NAMES = vector<string> {"level1.txt", "level2.txt", "level3.txt", "level4.txt"};

class Game {
private:
    int numLives;
    bool godMode;
public:
    vector<Level> levels;
    int currentLevelIndex;
    
    Game();
    Game(int _numLives);
    void draw(RenderWindow& window, int levelIndex, bool isGodeMode);
    bool isOver() {return numLives == 0;};
    Text livesCounter;
    Font fontType;
    bool getGodMode() {return godMode;};
    void setGodMode(bool isGodMode) {godMode = isGodMode;};
    void initGodMode(Level &currentLevel);
};


#endif /* game_hpp */
