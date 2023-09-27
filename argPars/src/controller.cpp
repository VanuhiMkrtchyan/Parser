#include "../hpp/controller.hpp"

#include <sstream>


void Controller::run(){
    auto input = user->getInput(); //<string>
    auto tokens = parser->tokenize(input); //vector<string>
    Op_Val_Pair_List Op_Value_list;
    std::string cmd = parser->make_command(tokens, Op_Value_list); 
    auto result = command_registry->operator[](cmd)->execute(Op_Value_list);
    user->displayOutput(result); 
}

// c++ src/*.cpp -fsanitize=address -g3
///TODO: check command execute, if add command was found, line 11