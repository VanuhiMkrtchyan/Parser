#ifndef COMMAND_BUILDER_HPP
#define COMMAND_BUILDER_HPP

#include "../Items/item.hpp"
#include "../Commands/command.hpp"

class CommandBuilder{
    public:
        virtual void add_item_name(std::string) = 0;
        virtual void add_top_left(Item::Coord) = 0;
        virtual void add_bottom_right(Item::Coord) = 0;
        virtual void add_ID(Item::Size) = 0;
        virtual void add_width(Item::Size) = 0;
        virtual void add_height(Item::Size) = 0;
        virtual CommandPtr get_result() = 0;
};

using CommandBuilderPtr = std::unique_ptr<CommandBuilder>;
#endif //COMMAND_BUILDER_HPP