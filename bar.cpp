//
//  bar.cpp
//  arkanoid
//
//  Created by Jeremy Rodgers and Adam Quintana on 9/17/18.
//

#include "bar.hpp"
#include "field.hpp"
#include <iostream>
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

const Color BAR_COLOR = Color(180, 180, 180, 255);

Bar::Bar(){};

Bar::Bar(Vector2f _dimension, Vector2f _position, int _speed){
    speed = _speed;
    shape.setSize(_dimension);
    shape.setPosition(_position);
    shape.setFillColor(BAR_COLOR);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1);
};

int Bar::moveLeft(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto left = fieldPosition.x;
    auto barPosition = getPosition();
    auto movement = 0;
    if (barPosition.x > left) {
        movement = speed * -1;
        shape.move(speed * -1, 0);
    } else {
        shape.setPosition(left, barPosition.y);
    }
    return movement;
};

int Bar::moveRight(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto fieldSize = field.getShape().getSize();
    auto right = fieldPosition.x + fieldSize.x;
    auto barPosition = getPosition();
     auto movement = 0;
    if (barPosition.x  + shape.getSize().x < right) {
        shape.move(speed, 0);
        movement = speed;
    } else {
        shape.setPosition(right - shape.getSize().x, barPosition.y);
    }
    return movement;
};
