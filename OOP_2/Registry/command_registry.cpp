#include "command_registry.hpp"

CommandRegisrty::CommandRegisrty(){
    Cmd_Reg["add"] = std::make_unique<Add_Command>();

}

CommandPtr const CommandRegisrty::operator[](const std::string command){
    return Cmd_Reg[command];
}
