
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
        for( int i = 0 ; i < game.levels.size(); i++){
            game.setGodMode(false);
            bool skipLevel = false;
            
            //update title
            window.setTitle("A&J's Arkanoid: " + game.levels[i].getName() + " by " + game.levels[i].getAuthor());
            
            // run level until skipped or game over
            while(window.isOpen() && !game.isOver() && !skipLevel) {
                if (game.levels[i].isComplete()) {
                    game.levels[i] = Level(LEVEL_NAMES[i], false);
                    break;
                }
                
                // check all the window's events that were triggered since the last iteration of the loop
                Event event;
                while (window.pollEvent(event))
                {
                    if(event.KeyPressed){
                        if(Keyboard::isKeyPressed(Keyboard::Left)){
                            game.levels[i].bar.moveLeft(game.levels[i].field);
                        } else if(Keyboard::isKeyPressed(Keyboard::Right)){
                            game.levels[i].bar.moveRight(game.levels[i].field);
                        } else if(Keyboard::isKeyPressed(Keyboard::Up)){
                            if (game.getGodMode()) {
                                game.levels[i].bar.moveUp(game.levels[i].field);
                            }
                        } else if(Keyboard::isKeyPressed(Keyboard::Down)){
                            if (game.getGodMode()) {
                                game.levels[i].bar.moveDown(game.levels[i].field);
                            }
                        } else if(Keyboard::isKeyPressed(Keyboard::Escape)){
                            skipLevel = true;
                            game.levels[i] = Level(LEVEL_NAMES[i], false);
                        } else if(Keyboard::isKeyPressed(Keyboard::Space)){
                            game.levels[i].ball.start();
                        } else if(Keyboard::isKeyPressed(Keyboard::G)){
                            game.setGodMode(true);
                            game.levels[i].field = Field(game.getGodMode());
                            auto fieldWidth = game.levels[i].field.getShape().getSize().x;
                            auto fieldLeft = game.levels[i].field.getShape().getPosition().x;
                            auto barPosition = game.levels[i].bar.getPosition();
                            auto ballVelocity = game.levels[i].ball.getVelocity();
                            game.levels[i].bar = Bar(Vector2f(fieldWidth, BAR_HEIGHT), Vector2f(fieldLeft, barPosition.y), 100);
                            game.levels[i].ball.setVelocity(ballVelocity.x * 5, ballVelocity.y * 5);
                        }
                    }
                    
                    // "close requested" event: we close the window
                    if (event.type == Event::Closed)
                        window.close();
                }
                
                // clear the window
                window.clear(BACKGROUND_COLOR);
                
                // draw everything here...
                game.draw(window, i, game.getGodMode());
                
                // end the current frame
                window.display();
            }
        }
    }
    return 0;
}
