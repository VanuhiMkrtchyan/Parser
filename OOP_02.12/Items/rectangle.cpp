#include <iostream>
#include <string>
#include <memory>

#include "rectangle.hpp"
#include "../Serialization/i_serialize.hpp"

Rectangle::Rectangle(Item::Coord p1, Item::Coord p2) : tl_{p1}, br_{p2}{
    type_ = Item::TYPE::Rect;
}

/*void Rectangle::set_attribute(std::string atribute, std::string val){
    if(atribute == "-x1"){
        p1_.set_x(std::stod(val));
    }
    if(atribute == "-y1"){
        p1_.set_y(std::stod(val));
    }
    if(atribute == "-x2"){
        p2_.set_x(std::stod(val));
    }
    if(atribute == "-x1"){
        p2_.set_y(std::stod(val));
    }

}*/


std::unique_ptr<Item> Rectangle::clone() const{
    return std::move(std::make_unique<Rectangle>());
}

void Rectangle::accept(I_Serializer& s){
    s.visit();

}
    