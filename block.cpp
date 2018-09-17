#include "block.hpp"

Block::Block(int _height, int _width, int _xPosition, int _yPosition, int _numHits, bool _isBreakable) {
    height = _height;
    width = _width;
    xPosition = _xPosition;
    xPosition = _yPosition;
    numHits = _numHits;
    isBreakable = _isBreakable;
}
