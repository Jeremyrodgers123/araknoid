
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "block.hpp"
#include "ball.hpp"
#include "bar.hpp"

using namespace std;
using namespace sf;

int main() {
    auto block = Block(50, 100, 10, 20, 1, false);
    auto ball = Ball();
    auto bar = Bar(30 , 500);
    
    sf::RenderWindow window(sf::VideoMode(1200, 900), "My window");
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Left)){
                    bar.moveLeft();
                }else if(Keyboard::isKeyPressed(Keyboard::Right)){
                    bar.moveRight();
                    //break;
                }
            }
            
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...
        
        window.draw(block.getShape());
        window.draw(ball.getShape());
        window.draw(bar.getShape());
        // end the current frame
        window.display();
    }
    return 0;
}
