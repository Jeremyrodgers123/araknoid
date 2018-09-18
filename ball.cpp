//
//  ball.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include "ball.hpp"
#include "block.hpp"

using namespace sf;
using namespace std;

const Color BALL_COLOR = Color(50, 150, 12, 255);
const Vector2f BALL_START_POSITION = Vector2f(550, 770);

Ball::Ball() {
    shape.setRadius(8);
    shape.setOutlineColor(BALL_COLOR);
    shape.setFillColor(BALL_COLOR);
    shape.setPosition(BALL_START_POSITION);
    direction.x = -1;
    direction.y = -1;
}

bool Ball::isHit(FloatRect obstacle) {
    return obstacle.contains(shape.getPosition());
}

void Ball::isHit(Block block){
    if (block.isActive) {
        if(isHit(block.getShape().getLocalBounds())) {
            block.hit();
            //reverse ball direction
        }
    }
}

void Ball::isHit(Bar bar){
    if(isHit(bar.getShape().getLocalBounds())) {
        //reverse ball direction
    }
};

void Ball::move() {
    auto currentPosition = getPosition();
    if (currentPosition.x < 0 || currentPosition.x > 1200) {
        direction.x *= -1;
    }
    if (currentPosition.y < 0 || currentPosition.y > 900) {
        direction.y *= -1;
    }
    shape.move(direction);
}

