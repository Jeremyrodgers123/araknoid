
#include <SFML/Graphics.hpp>

using namespace sf;

class Block {
private:
    RectangleShape shape;
    int numHits;
    bool isBreakable;
public:
    Block(int _height, int _width, int _xPosition, int _yPosition, int _numHits, bool _isBreakable);
    
};
