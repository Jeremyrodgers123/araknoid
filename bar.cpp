//
//  bar.cpp
//  arkanoid
//
//  Created by Jeremy Rodgers and Adam Quintana on 9/17/18.
//

#include "bar.hpp"
#include <iostream>
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

const int BAR_HEIGHT = 10;
const Color BAR_COLOR = Color(180, 180, 180, 255);
const Vector2f BAR_START_POSITION = Vector2f(500, 800);

Bar::Bar(){};

Bar::Bar(int _width){
    shape.setSize(Vector2f(_width, BAR_HEIGHT));
    shape.setPosition(BAR_START_POSITION);
    shape.setFillColor(BAR_COLOR);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(2);
};

void Bar::moveLeft(){
    shape.move(-20, 0);
};

void Bar::moveRight(){
    shape.move(20, 0);
};
