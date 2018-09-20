//
//  bar.hpp
//  arkanoid
//
//  Created by Jeremy Rodgers and Adam Quintana on 9/17/18.
//

#ifndef bar_hpp
#define bar_hpp

#include <stdio.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include "field.hpp"

using namespace sf;
using namespace std;

class Bar {
    RectangleShape shape;
    int speed;
public:
    Bar();
    Bar(Vector2f _dimension, Vector2f _position, int _speed);
    
    RectangleShape getShape(){ return shape;};
    Vector2f getPosition() { return shape.getPosition();};
    int moveLeft(Field field);
    int moveRight(Field field);
};
#endif /* bar_hpp */
