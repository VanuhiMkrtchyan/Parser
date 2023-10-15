#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle : public Item{
    public:
        Rectangle() = default;
        void draw() override;
};

#endif //RECTANGLE_HPP