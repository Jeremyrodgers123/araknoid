//
//  bar.hpp
//  arkanoid
//
//  Created by Jeremy Rodgers and Adam Quintana on 9/17/18.
//

#ifndef bar_hpp
#define bar_hpp

#include <stdio.h>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;
using namespace std;

class Bar {
      RectangleShape shape;
public:
    Bar();
    Bar(int _width);
    
    RectangleShape getShape(){ return shape;};
    Vector2f getPosition() { return shape.getPosition();};
    void moveLeft();
    void moveRight();
};
#endif /* bar_hpp */
