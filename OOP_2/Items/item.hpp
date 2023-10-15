#ifndef ITEM_HPP
#define ITEM_HPP

class Item{
    public:
        Item() = default;
        Item(Coord top_left, Coord bottom_right);
        Item(Coord top_left, Size width, Size height);
        void set_ID(const ID);
        virtual void draw() = 0;
    public:
        using ID = int;
        using Size = int;

        struct Coord{
            int x, y;
            Coord() = default;
            explicit Coord(int x, int y) : x{x}, y{y}{}

        };
    private:
        Coord top_left, bottom_right;
        Size width, height;
        ID id;


};

#endif //ITEM_HPP