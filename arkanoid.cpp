
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "game.hpp"
#include "level.hpp"

using namespace std;
using namespace sf;

const int NUMBER_OF_LIVES = 3;
const int WINDOW_HEIGHT = 1500;
const int WINDOW_WIDTH = 1500;
const Color BACKGROUND_COLOR = Color::Black;

int main() {
    // initialize random seed
    srand ((int)time(NULL));
    
    auto game = Game(NUMBER_OF_LIVES);
    
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "A&J's Arkanoid");
        
    // run the program as long as the window is open or game over
    while (window.isOpen() && !game.isOver()) {
        
        // loop through levels
    
        for (auto level : game.levels) {
            bool skipLevel = false;
//            if (level.isComplete()) {
//                continue;
//            }
            
            //update title
            window.setTitle("A&J's Arkanoid: " + level.getName() + " by " + level.getAuthor());
            
            // run level until skipped or game over
            while(window.isOpen() && !game.isOver() && !skipLevel) {
                
                // check all the window's events that were triggered since the last iteration of the loop
                Event event;
                while (window.pollEvent(event))
                {
                    if(event.KeyPressed){
                        if(Keyboard::isKeyPressed(Keyboard::Left)){
                            level.bar.moveLeft(level.field);
                        }else if(Keyboard::isKeyPressed(Keyboard::Right)){
                            level.bar.moveRight(level.field);
                        } else if(Keyboard::isKeyPressed(Keyboard::Escape)){
                            skipLevel = true;
                        } else if(Keyboard::isKeyPressed(Keyboard::Space)){
                            //skipLevel = true;
                        }
                    }
                    
                    // "close requested" event: we close the window
                    if (event.type == Event::Closed)
                        window.close();
                }
                
                // clear the window
                window.clear(BACKGROUND_COLOR);
                
                // draw everything here...
                level.draw(window);
                
                // end the current frame
                window.display();
            }
        }
    }
    return 0;
}
