#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"
#include "../builder_factory/item_factory.hpp"

class Add_Command : public Command{
    public:
        Add_Command() = default;
        void execute(I_Document&) override;
        CommandPtr clone() const override;
    public:
        void set_ID_count(int ic);
        static int get_ID_Count();

        void set_item_name(std::string);
        std::string get_item_name();

        void set_top_left(Item::Coord);
        Item::Coord get_top_left();

        void set_bottom_right(Item::Coord);
        Item::Coord get_bottom_left();

        void set_width(Item::Size);
        Item::Size get_width();

        void set_height(Item::Size);
        Item::Size get_height();

    private:
        static int ID_count;
        std::string item_name;
        Item::Coord top_left, bottom_right;
        Item::Size width, height;
    private:
        ItemBuilderFactory item_factory;
};
#endif //ADD_COMMAND_HPP