#include "block.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

Block::Block(int _height, int _width, int _xPosition, int _yPosition, int _numHits, bool _isBreakable) {
    auto v2f = Vector2f(_width, _height);
    shape.setSize(v2f);
    numHits = _numHits;
    isBreakable = _isBreakable;
}
