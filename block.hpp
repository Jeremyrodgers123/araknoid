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

class Block {
private:
    RectangleShape shape;
    bool isBreakable;
public:
    bool isActive;
    
    Block();
    Block(Vector2f _dimensions, Vector2f _position, int _colorIndex, bool _isBreakable, bool _isActive);
    
    RectangleShape getShape(){ return shape;};
    void collision();
    static const vector<Color> BREAKABLE_COLORS;
    static const Color UNBREAKABLE_COLOR;
};

#endif /* block_hpp */
