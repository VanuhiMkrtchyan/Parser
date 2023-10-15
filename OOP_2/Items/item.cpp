#include "item.hpp"

Item::Item(Coord top_left, Coord bottom_right) : top_left{top_left}, bottom_right{bottom_right}{
    width = bottom_right.x - top_left.x;
    heigth = top_left.y - bottom_right.y;
}

Item::Item(Coord top_left, Size width, Size height) : top_left{top_left}, width{width}, height{height}{
    bottom_rigth = Coord(top_left.x + width, top_left.y - height);
}
