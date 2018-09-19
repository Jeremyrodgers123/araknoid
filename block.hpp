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
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

const Color BLACK = Color::Black;
const Color RED = Color(225, 10, 10, 255);
const Color GREEN = Color(10, 225, 10, 255);
const Color WHITE = Color::White;
const Color ORANGE = Color(245, 150, 21, 255);
const Color LIGHT_BLUE = Color(122, 18, 250, 255);
const Color DARK_BLUE = Color(10, 10, 225, 255);
const Color PINK = Color(240, 15, 245, 255);
const Color YELLOW = Color(251, 255, 66, 255);
const Color GREY = Color(180, 180, 180, 255);

const vector<Color> COLORS = {BLACK, RED, GREEN, WHITE, ORANGE, LIGHT_BLUE, DARK_BLUE, PINK, YELLOW, GREY};

class Block {
private:
    RectangleShape shape;
public:
    bool isBreakable;
    bool isActive;
    
    Block();
    Block(Vector2f _dimensions, Vector2f _position, int _colorIndex);
    
    RectangleShape getShape(){ return shape;};
    void collision();
};

#endif /* block_hpp */
