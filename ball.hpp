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
#include "block.hpp"
#include "bar.hpp"

using namespace sf;
using namespace std;

class Ball {
private:
    CircleShape shape;
    Vector2f prevPosition;
public:
    Vector2f velocity;
    
    Ball();
    Vector2f getPosition() {return shape.getPosition();};
    Vector2f getPrevPosition(){return prevPosition;};
    CircleShape getShape() {return shape;};
    bool detectCollision(Block block);
    bool detectCollision(Bar bar);
    bool detectCollision(FloatRect obstacle);
    void move();
};

#endif /* ball_hpp */
