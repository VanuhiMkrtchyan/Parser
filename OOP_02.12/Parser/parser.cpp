#include "parser.hpp"

std::string Command_Parser::parse(std::string& str){
    auto token = token_.get_token(str, 1);
}