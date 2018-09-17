//
//  block.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "ball.hpp"

using namespace sf;
using namespace std;

const int MAX_HITS = 3;
const vector<Color> COLORS = {Color::Red, Color::Yellow, Color::Green};

Block::Block(int _height, int _width, int _xPosition, int _yPosition, int _remainingHits, bool _isBreakable) {
    isActive = true;
    shape.setSize(Vector2f(_width, _height));
    shape.setPosition(Vector2f(_xPosition, _yPosition));
    shape.setFillColor(COLORS[MAX_HITS - _remainingHits]);
    shape.setOutlineColor(Color::White);
    shape.setOutlineThickness(5);
    remainingHits = _remainingHits;
    isBreakable = _isBreakable;
}

void Block::hit() {
    remainingHits--;
    if (remainingHits == 0) {
        isActive = false;
    } else {
        shape.setFillColor(COLORS[MAX_HITS - remainingHits]);
    }
}


