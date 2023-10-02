#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <vector>
#include <string>

using Op_Val_Pair = std::pair<std::string, double>;
using Op_Val_Pair_List = std::vector<Op_Val_Pair>;
class Command{
    public:
        Command(){};
        virtual double execute(Op_Val_Pair_List& args) = 0;
        ~Command(){};
};

#endif //COMMAND_HPP
