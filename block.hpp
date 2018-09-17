#include <string>
#include <vector>

class Block {
private:
    int width;
    int height;
    int xPosition;
    int yPosition;
    int numHits;
    bool isBreakable;
public:
    Block(int _height, int _width, int _xPosition, int _yPosition, int _numHits, bool _isBreakable);
    
};
