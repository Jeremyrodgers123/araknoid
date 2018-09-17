//
//  bar.hpp
//  arkanoid
//
//  Created by Jeremy Rodgers on 9/17/18.
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
    Bar(int _width, int _xPosition);
    RectangleShape getShape(){ return shape;};
    Vector2f getPosition() { return shape.getPosition();};
    void moveLeft();
    void moveRight();
};
#endif /* bar_hpp */
