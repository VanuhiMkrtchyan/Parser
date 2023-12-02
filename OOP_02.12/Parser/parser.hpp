#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include "tokenizer.hpp"

class Command_Parser{
    public:
        std::string parse(std::string&);
    private:
        Tokenizer token_;
};

#endif //COMMAND_PARSER