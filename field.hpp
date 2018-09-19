//
//  field.hpp
//  arkanoid
//
//  Created by Adam Quintana and Jeremy Rodgers on 9/19/18.
//

#ifndef field_hpp
#define field_hpp

#include <stdio.h>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Field {
private:
    RectangleShape shape;
    FloatRect bounds;
public:
    Field();
    
    RectangleShape getShape() {return shape;};
    FloatRect getRect() {return bounds;};
};

#endif /* field_hpp */
