#include "command_director.hpp"

CommandPtr CommandDirector::construct(CommandBuilderPtr builder, OptionsMap options){
    builder->add_ID(options["ID"]);
    builder->add_height(options["height"]);
    builder->add_width(options["width"]);
    builder->add_item_name(options["item"]);
    builder->add_top_left(options["top_letf"]);
    builder->add_bottom_rigth(options["bottom_right"]);
    return builder->get_result();
}