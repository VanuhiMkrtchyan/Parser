#ifndef ADD_COMMAND_BUILDER_HPP
#define ADD_COMMAND_BUILDER_HPP

#include "command_builder.hpp"
#include "../Commands/add_command.hpp"

class AddCommandBuilder{
    public:
        AddCommandBuilder(std::map<std::string, std::string> operands);
        void add_item_name(std::string) override;
        void add_top_left(Item::Coord) override;
        void add_bottom_left(Item::Coord) override;
        void add_width(Item::Size) override;
        void add_height(Item::Size) override;
        void CommandPtr get_result() override;
    private:
        std::unique_ptr<Add_Command> add_command;
};

#endif //ADD_COMMAND_BUILDER_HPP