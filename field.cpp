//
//  field.cpp
//  arkanoid
//
//  Created by Adam Quintana on 9/19/18.
//

#include "field.hpp"

const int FIELD_WIDTH = 1200;
const int FIELD_HEIGHT = 1400;
const int FIELD_BUFFER = 100;
const Color GREY = Color(180, 180, 180, 255);

Field::Field() {
    shape.setSize(Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    shape.setPosition(Vector2f(FIELD_BUFFER, FIELD_BUFFER));
    shape.setFillColor(Color::Black);
    shape.setOutlineColor(GREY);
    shape.setOutlineThickness(20);
    bounds = shape.getGlobalBounds();
};

