#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include <string>
#include <sstream>
#include <variant>
#include <vector>

#include "../Commands/command.hpp"
#include "validate.hpp"

using Tokens = std::vector<std::string>;

class Parser{
    public:
        Parser() = default;
        Parser(std::string input): input_stream{input}{};
    public:
        CommandPtr parser(std::string input);
        Tokens tokenize();
        std::string determine_command(const Tokens);
        std::variant<std::string, int, void> determine_operands(const Tokens, std::string option);

        friend class Validate;
    private:
        std::string input_stream;

};

#endif //COMMAND_PARSER