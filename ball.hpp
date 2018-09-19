//
//  ball.hpp
//  arkanoid
//
//  Created by Adam Quintana & Jeremy Rodgers on 9/17/18.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include <SFML/Graphics/CircleShape.hpp>
#include "field.hpp"
#include "block.hpp"
#include "bar.hpp"

using namespace sf;
using namespace std;

class Ball {
private:
    CircleShape shape;
    Vector2f prevPosition;
    Vector2f velocity;
public:
    
    Ball();
    Ball(Vector2f _position, int _speed);
    
    Vector2f getPosition() {return shape.getPosition();};
    Vector2f getPrevPosition(){return prevPosition;};
    CircleShape getShape() {return shape;};
    void detectCollision(Field field);
    void detectCollision(Bar bar);
    bool detectCollision(Block block);
    void move();
    Vector2f getVelocity() {return velocity;};
};

#endif /* ball_hpp */
