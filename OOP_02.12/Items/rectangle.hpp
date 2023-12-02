#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"

class Rectangle : public Item {
    public:
        Rectangle(){
            type_ = Item::TYPE::Rect;
        }
        Rectangle(Coord tl, Coord br);
        void set_top_left(Coord p){tl_ = p;}
        void set_bottom_right(Coord p) {br_ = p;}
        Item::Coord get_top_left(){return tl_;}
        Item::Coord get_bottom_right(){return br_;}
        //void set_attribute(std::string, std::string) override;
        std::unique_ptr<Item> clone() const override;
        void accept(I_Serialize&) override;
    private:
        Item::Coord tl_;
        Item::Coord br_;
};

#endif //RECTANGLE_HPP