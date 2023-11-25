#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"

class Rectangle : public Item {
    public:
        Rectangle() = default;
        void draw() override;
};

#endif //RECTANGLE_HPP