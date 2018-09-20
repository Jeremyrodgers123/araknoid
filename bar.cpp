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

void Bar::moveLeft(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto left = fieldPosition.x;
    auto barPosition = getPosition();
    if (barPosition.x > left) {
        shape.move(speed * -1, 0);
    } else {
        shape.setPosition(left, barPosition.y);
    }
};

void Bar::moveRight(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto fieldSize = field.getShape().getSize();
    auto right = fieldPosition.x + fieldSize.x;
    auto barSize = shape.getSize();
    auto barPosition = getPosition();
    if (barPosition.x  + barSize.x < right) {
        shape.move(speed, 0);
    } else {
        shape.setPosition(right - barSize.x, barPosition.y);
    }
};

void Bar::moveUp(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto top = fieldPosition.y;
    auto barPosition = getPosition();
    if (barPosition.y > top) {
        shape.move(0, speed * -1);
    } else {
        shape.setPosition(barPosition.x, top);
    }
};

void Bar::moveDown(Field field){
    auto fieldPosition = field.getShape().getPosition();
    auto fieldSize = field.getShape().getSize();
    auto bottom = fieldPosition.y + fieldSize.y;
    auto barPosition = getPosition();
    auto barSize = shape.getSize();
    if (barPosition.y + barSize.y < bottom) {
        shape.move(0, speed);
    } else {
        shape.setPosition(barPosition.x, bottom - barSize.y);
    }
};
