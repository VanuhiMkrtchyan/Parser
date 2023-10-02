#include "../hpp/controller.hpp"

#include <sstream>


void Controller::run(){
    std::string input;
    std::cout << "Enter a command: ";
    while(true){
        auto input = user->getInput(); //<string>
        auto tokens = parser->tokenize(input); //vector<string>
        try{
            Op_Val_Pair_List Op_Value_list;
            std::string cmd = parser->make_command(tokens, Op_Value_list); 
            auto result = command_registry->operator[](cmd)->execute(Op_Value_list);
            user->displayOutput(result); 
            std::cout << "Enter a command: ";
        }
        catch(...){
            std::cerr << "Wrong arguments"<<std::endl;
            std::cout << "Enter a command: ";
        }
    }
}

// c++ src/*.cpp -fsanitize=address -g3