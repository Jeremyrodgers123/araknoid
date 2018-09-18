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
public:
    Vector2f direction;
    
    Ball();
    
    CircleShape getShape() {return shape;};
    Vector2f getPosition() {return shape.getPosition();};
    void isHit(Block block);
    void isHit(Bar bar);
    bool isHit(FloatRect);
    void move();
};

#endif /* ball_hpp */
