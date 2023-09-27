#ifndef PARSER_HPP
#define PARSER_HPP

#include <utility>
#include <sstream>
#include <vector>
#include <string>

#include "command.hpp"
#include <memory>
using TokensType = std::vector<std::string>;
using input_type = const std::string&;
using CommandType = const std::string&;

using Op_Val_Pair = std::pair<std::string, double>;
using CommandOperators = std::vector<Op_Val_Pair>;

class Parser{
    public:
        Parser() = default;
        TokensType tokenize(input_type input);
        std::string make_command(const TokensType token, Op_Val_Pair_List& op_value_list);
        void Validate_command(TokensType token);
        void Validate_operators(TokensType token);
        void Validate_values(TokensType value_vector);
    public:
        Op_Val_Pair op_value_list;
        //std::unique_ptr<Command> command_ = std::make_unique<Command>();

};



#endif // PARSER_HPP
