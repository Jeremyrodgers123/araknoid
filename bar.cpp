//
//  bar.cpp
//  arkanoid
//
//  Created by Jeremy Rodgers on 9/17/18.
//

#include "bar.hpp"
#include <iostream>
//Block(int _height, int _width, int _xPosition, int _yPosition, int _remainingHits, bool _isBreakable);
Bar::Bar( int _width, int _xPosition){
    int _height = 5;
    int _yPosition = 800;
    shape.setSize(Vector2f( _width, _height));
    shape.setPosition(Vector2f(_xPosition, _yPosition));
    shape.setFillColor(Color::White);
    shape.setOutlineColor(Color::White);
    shape.setOutlineThickness(2);
};
void Bar::moveLeft(){
    shape.move(-20 , 0);
};

void Bar::moveRight(){
    shape.move( 20 , 0);
    std::cout << "in move right" << std::endl;
};
