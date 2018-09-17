//
//  ball.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include "ball.hpp"
#include "block.hpp"

Ball::Ball() {
    shape.setRadius(10);
    shape.setOutlineColor(Color::White);
    shape.setFillColor(Color::White);
    shape.setPosition(100, 100);
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

