//
//  block.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "ball.hpp"
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

const Color RED = Color(225, 10, 10, 255);
const Color GREEN = Color(10, 225, 10, 255);
const Color WHITE = Color::White;
const Color ORANGE = Color(245, 150, 21, 255);
const Color LIGHT_BLUE = Color(122, 18, 250, 255);
const Color DARK_BLUE = Color(10, 10, 225, 255);
const Color PINK = Color(240, 15, 245, 255);
const Color YELLOW = Color(251, 255, 66, 255);

const Color Block::UNBREAKABLE_COLOR = Color(180, 180, 180, 255);
const vector<Color> Block::BREAKABLE_COLORS = {RED, GREEN, WHITE, ORANGE, LIGHT_BLUE, DARK_BLUE, PINK, YELLOW};

Block::Block(){};

Block::Block(Vector2f _dimensions, Vector2f _position, int _colorIndex, bool _isBreakable, bool _isActive) {
    isActive = _isActive;
    isBreakable = _isBreakable;
    shape.setSize(_dimensions);
    shape.setPosition(_position);
    if (isBreakable) {
        shape.setFillColor(BREAKABLE_COLORS[_colorIndex]);
    } else {
        shape.setFillColor(UNBREAKABLE_COLOR);
    }
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(5);
}

void Block::collision() {
    isActive = false;
}


