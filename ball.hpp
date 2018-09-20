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
    bool isInbounds;
    Ball();
    Ball(Vector2f _position, float _speed);
    void start();
    Vector2f getPosition() {return shape.getPosition();};
    Vector2f getPrevPosition(){return prevPosition;};
    CircleShape getShape() {return shape;};
    void detectCollision(Field field, bool isGodMode);
    void detectCollision(Bar bar);
    bool detectCollision(Block block);
    void move();
    void setSpeed(float _speed) {speed = _speed;};
    float getSpeed(){return speed;};
    Vector2f getVelocity() {return velocity;};
    void setVelocity(float _x, float _y) {velocity = Vector2f(_x, _y);};
};

#endif /* ball_hpp */
