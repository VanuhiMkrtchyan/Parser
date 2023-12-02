#include <memory>
#include <string>

#include "controller.hpp"

void Controller::run(){
    auto io_ = std::shared_ptr<IO_Stream>();
    std::string input_ = io_.get_input();
    auto  command_name = parser_.parse(input_);
    auto command = cmd_factory_registry_[command_name]->create_command(input_);
    auto out = command->execute();
    io_.display_output(std::string(out));
}
