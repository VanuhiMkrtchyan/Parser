#include "command_director.hpp"


CommandPtr CommandDirector::construct(CommandBuilderPtr builder, OptionsMap options){
    builder->add_ID(options[std::string("ID")]);
    builder->add_height(options[std::string("height")]);
    builder->add_width(options[std::string("width")]);
    builder->add_item_name(options[std::string("item")]);
    builder->add_top_left(options[std::string("top_letf")]);
    builder->add_bottom_right(options[std::string("bottom_right")]);
    return builder->get_result();
}