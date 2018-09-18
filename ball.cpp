//
//  ball.cpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/17/18.
//

#include "ball.hpp"
#include "block.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const Color BALL_COLOR = Color(50, 150, 12, 255);
const Vector2f BALL_START_POSITION = Vector2f(550, 770);

Ball::Ball() {
    shape.setRadius(8);
    shape.setOutlineColor(BALL_COLOR);
    shape.setFillColor(BALL_COLOR);
    shape.setPosition(BALL_START_POSITION);
    velocity.x = -1;
    velocity.y = -1;
    prevPosition = BALL_START_POSITION;
}

bool Ball::detectCollision(FloatRect obstaclePos) {
    //ball center
    Vector2f ballCenter = getPosition();
    auto right = obstaclePos.left + obstaclePos.width;
    auto bottom = obstaclePos.top + obstaclePos.height;
    if(obstaclePos.contains(ballCenter)){
        cout << "collision" <<endl;
        if(!(prevPosition.x > obstaclePos.left && prevPosition.x < right)){
            cout << "change x direction" << endl;
            velocity.x *= -1;
        }else if (!(prevPosition.y > obstaclePos.top && prevPosition.y < bottom)){
            cout << "change y direction" << endl;
            velocity.y *= -1;
        }
        return true;
    };
    return false;
}

bool Ball::detectCollision(Block block){
    
    
        if(detectCollision(block.getShape().getGlobalBounds())) {
            //reverse ball direction
            
            return true;
        }
    
    return false;
}

bool Ball::detectCollision(Bar bar){
    if(detectCollision(bar.getShape().getLocalBounds())) {
        //reverse ball direction
        return true;
    }
    return false;
};

void Ball::move() {
    auto currentPosition = getPosition();
    if (currentPosition.x < 0 || currentPosition.x > 1200) {
        velocity.x *= -1;
    }
    if (currentPosition.y < 0 || currentPosition.y > 900) {
        velocity.y *= -1;
    }
    prevPosition = getPosition();
    shape.move(velocity);
}



