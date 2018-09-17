
#include <iostream>
#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "ball.hpp"

using namespace std;

int main() {
    auto block = Block(100, 50, 10, 20, 1, false);
    auto ball = Ball();
    
    sf::RenderWindow window(sf::VideoMode(1200, 900), "My window");
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...
        
        
//        rectangle.setSize(sf::Vector2f(100, 50));
//        rectangle.setOutlineColor(sf::Color::Red);
//        rectangle.setOutlineThickness(5);
//        rectangle.setPosition(10, 20);
        window.draw(block.getShape());
        window.draw(ball.getShape());
        // end the current frame
        window.display();
    }
    return 0;
}
