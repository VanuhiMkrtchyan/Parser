#ifndef ITEM_HPP
#define ITEM_HPP

class Item{
    public:
        struct Coord{
            int x, y;
            Coord() = default;
            Coord(int x, int y) : x{x}, y{y}{}

        };
        using ID = int;
        using Size = int;
    public:
        Item() {
            static ID count = 1;
            id = count++;
        }
        /// TODO: move Item ctors to Rectangle
        Item(Coord top_left, Coord bottom_right);
        Item(Coord top_left, Size width, Size height);
        void set_ID(const ID);
        ID get_ID();
        virtual void draw() = 0;
    public:
        void set_ID(ID);
        ID get_ID();

        void set_top_left(Coord);
        Coord get_top_left();

        void set_bottom_right(Coord);
        Coord get_bottom_left();

        void set_width(Size);
        Size get_width();

        void set_height(Size);
        Size get_height();


    private:
        Coord top_left, bottom_right;
        Size width, height;
        ID id;


};

using ItemPtr = std::unique_ptr<Item>;

#endif //ITEM_HPP