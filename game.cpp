//
//  game.cpp
//  arkanoid
//
//  Created by Adam Quintana on 9/18/18.
//

#include <vector>
#include "game.hpp"
#include "level.hpp"

using namespace std;

const vector<string> LEVEL_NAMES = vector<string> {"level1.txt", "level2.txt", "level3.txt"};

Game::Game() {}

Game::Game(int _numLives) {
    numLives = _numLives;
    for (string levelName : LEVEL_NAMES) {
        levels.push_back(Level(levelName, numLives));
    }
}
