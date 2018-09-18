
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "level.hpp"
#include "block.hpp"
#include "ball.hpp"
#include "bar.hpp"

using namespace std;
using namespace sf;

const int WINDOW_HEIGHT = 900;
const int WINDOW_WIDTH = 1200;
const Color BACKGROUND_COLOR = Color::Black;

int main() {
    // initialize random seed
    srand ((int)time(NULL));
    
    auto levelOne = Level(WINDOW_WIDTH, 1);
    
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "A&J's Arkanoid");
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            if(event.KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Left)){
                    levelOne.bar.moveLeft();
                }else if(Keyboard::isKeyPressed(Keyboard::Right)){
                    levelOne.bar.moveRight();
                }
            }
            
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }
        
        // clear the window
        window.clear(BACKGROUND_COLOR);
        
        // draw everything here...
        levelOne.draw(window);
        
        // end the current frame
        window.display();
    }
    return 0;
}
