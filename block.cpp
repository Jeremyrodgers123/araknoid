//
//  block.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "ball.hpp"

using namespace sf;
using namespace std;

Block::Block(){};

Block::Block(Vector2f _dimensions, Vector2f _position, int _colorIndex) {
    switch (_colorIndex) {
        case 0:
            isActive = false;
            isBreakable = true;
            break;
        case 9:
            isActive = true;
            isBreakable = false;
        default:
            isActive = true;
            isBreakable = true;
            break;
    }
    shape.setSize(_dimensions);
    shape.setPosition(_position);
    shape.setFillColor(COLORS[_colorIndex]);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1);
}

void Block::collision() {
    if (isBreakable) {
        isActive = false;
    }
}


