#include <iostream>

#include "rectangle.hpp"

void Rectangle::draw(){
    std::cout << "Rectangle is drawn with width: " << "  height: " << get_height() << " in Coordinates: " << Coord::x << "  " << Coord::y << std::endl;
}