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
const int BALL_RADIUS = 8;

Ball::Ball(){};

Ball::Ball(Vector2f _position, float _speed) {
    shape.setRadius(BALL_RADIUS);
    shape.setOutlineColor(BALL_COLOR);
    shape.setFillColor(BALL_COLOR);
    shape.setPosition(_position);
    velocity = Vector2f(0, 0);
    speed = _speed;
    prevPosition = _position;
    isInbounds = true;
}

bool Ball::detectCollision(Block block){
    Vector2f ballCenter = getPosition();
    auto obstacleRect = block.getShape().getGlobalBounds();
    auto top = obstacleRect.top;
    auto bottom = obstacleRect.top + obstacleRect.height;
    auto left = obstacleRect.left;
    auto right = obstacleRect.left + obstacleRect.width;
    if(obstacleRect.contains(ballCenter) && !obstacleRect.contains(prevPosition)){
        cout << "collision" <<endl;
        if(!(prevPosition.x > left && prevPosition.x < right)){
            cout << "change x direction" << endl;
            velocity.x *= -1;
        } else if (!(prevPosition.y > top && prevPosition.y < bottom)){
            cout << "change y direction" << endl;
            velocity.y *= -1;
        }
        return true;
    }
    return false;
    
}

void Ball::detectCollision(Bar bar){
    Vector2f ballCenter = getPosition();
    auto obstacleRect = bar.getShape().getGlobalBounds();
    auto top = obstacleRect.top;
    auto bottom = obstacleRect.top + obstacleRect.height;
    auto left = obstacleRect.left;
    auto right = obstacleRect.left + obstacleRect.width;
    auto width = obstacleRect.width;
    if(obstacleRect.contains(ballCenter) && !obstacleRect.contains(prevPosition)){
        auto firstQuarter = left + (width*0.25);
        auto lastQuarter = right - (width*0.25);
        if (ballCenter.x < firstQuarter || ballCenter.x > lastQuarter) {
            velocity.x *= 1.5;
        } else {
            velocity.x = velocity.x < 0 ? -1 : 1;
        }
        cout << "collision" <<endl;
        if(!(prevPosition.x > left && prevPosition.x < right)){
            cout << "change x direction" << endl;
            velocity.x *= -1;
        } else if (!(prevPosition.y > top && prevPosition.y < bottom)){
            cout << "change y direction" << endl;
            velocity.y *= -1;
        }
    }
};

void Ball::detectCollision(Field field, bool isGodMode){
    auto fieldPosition = field.getShape().getPosition();
    auto fieldSize =field.getShape().getSize();
    auto top = fieldPosition.y;
    auto bottom = fieldPosition.y + fieldSize.y;
    auto left = fieldPosition.x;
    auto right = fieldPosition.x + fieldSize.x;

    auto ballPosition = getPosition();
    if (ballPosition.x < left || ballPosition.x > right) {
        shape.setPosition(prevPosition);
        velocity.x *= -1;
    }
    if (ballPosition.y < top ) {
        velocity.y *= -1;
    }else if( ballPosition.y > bottom){
        velocity.y *= -1;
        if (!isGodMode) {
            isInbounds = false;
        }
    }
};

void Ball::move() {
    prevPosition = getPosition();
    shape.move(velocity);
}
void Ball::shift(int barMovement){
    shape.move(barMovement, 0);
};

void Ball::start(){
    if (velocity.x == 0 && velocity.y == 0) {
        velocity = Vector2f(-1 * speed,-1 *speed );
    }
}

void Ball::centerWithBar(int barWidth){
    Vector2f ballPosition = getPosition();
    float ballRadius = getShape().getRadius();
    shape.move( barWidth/2 - ballRadius, -1*(ballRadius *2));
}

