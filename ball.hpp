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

class Ball {
private:
    CircleShape shape;
public:
    Ball();
    CircleShape getShape() {return shape;};
    void isHit(Block block);
    void isHit(Bar bar);
    bool isHit(FloatRect);
};

#endif /* ball_hpp */
