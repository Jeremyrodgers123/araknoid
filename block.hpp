//
//  block.hpp
//  arkanoid
//
//  Created by Adam Quintana & Jeremy Rodgers on 9/17/18.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Block {
private:
    RectangleShape shape;
    int remainingHits;
    bool isBreakable;
public:
    bool isActive;
    Block(int _height, int _width, int _xPosition, int _yPosition, int _remainingHits, bool _isBreakable);
    RectangleShape getShape(){ return shape;};
    Vector2f getPosition() { return shape.getPosition();};
    void hit();
};

#endif /* block_hpp */
