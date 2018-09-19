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

class Game {
private:
    int numLives;
public:
    vector<Level> levels;
    
    Game();
    Game(int _numLives);
    
    bool isOver() {return numLives == 0;};

};

#endif /* game_hpp */
