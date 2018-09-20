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
    float speed;
public:
    float getSpeed(){return speed;};
    bool isInbounds;
    Ball();
    Ball(Vector2f _position, float _speed);
    void start();
    Vector2f getPosition() {return shape.getPosition();};
    Vector2f getPrevPosition(){return prevPosition;};
    CircleShape getShape() {return shape;};
    void detectCollision(Field field);
    void detectCollision(Bar bar);
    bool detectCollision(Block block);
    void move();
    void shift(int barMovement);
    Vector2f getVelocity() {return velocity;};
    void centerWithBar(int barWidth);
};

#endif /* ball_hpp */
