#include "block.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

Block::Block(int _height, int _width, int _xPosition, int _yPosition, int _numHits, bool _isBreakable) {
    shape.setSize(Vector2f(_height, _width));
    shape.setPosition(Vector2f(_xPosition, _yPosition));
    shape.setFillColor(Color::Green);
    shape.setOutlineColor(Color::White);
    shape.setOutlineThickness(5);
    numHits = _numHits;
    isBreakable = _isBreakable;
    
}

void Block::isHit(){
    numHits -= 1;
    if (numHits <= 0 ){
        isActive = false;
    }
}
