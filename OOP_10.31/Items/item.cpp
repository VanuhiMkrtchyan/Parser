#include "item.hpp"

Item::Item(Coord top_left, Coord bottom_right) : top_left{top_left}, bottom_right{bottom_right}{
    width = bottom_right.x - top_left.x;
    height = top_left.y - bottom_right.y;
}

Item::Item(Coord top_left, Size width, Size height) : top_left{top_left}, width{width}, height{height}{
    bottom_right = Coord(top_left.x + width, top_left.y - height);
}

void Item::set_ID(ID i){
    id = i;
}
ID Item::get_ID(){
    return id;
}

void Item::set_top_left(Coord left){
    top_left = left;
}
Coord Item::get_top_left(){
    return top_left;
}

void Item::set_bottom_right(Coord right){
    bottom_right = right;
}
Coord Item::get_bottom_left(){
    return bottom_right;
}

void Item::set_width(Size w){
    width = std::stoi(w);
}
Size Item::get_width(){
    return width;
}

void Item::set_height(Size h){
    height = std::stoi(h);
}
Size Item::get_height(){
    return height;
}
