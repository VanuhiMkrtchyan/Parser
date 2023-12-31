#include "command_parser.hpp"


Tokens Parser::tokenize(){
    Tokens tokens;
    std::stringstream ss(input_stream);
    if(ss.fail()){
        throw std::invalid_argument("Parser tokenization is failed");
    }
    std::string temp;
    while(std::getline(ss, temp, ' '))
    { 
        if(!temp.empty())
            tokens.push_back(temp);
    }    
    return tokens;
}

std::string Parser::determine_command(const Tokens token){
    Validate::validate_command(token[0]);
    return token[0];
}

/*std::variant<std::string, int, void> Parser::determine_operands(const Tokens& tokens, std::string option){
    for(auto token : tokens){
        if(token == option){
            validate_operands(token.next())
            return token.next();
        }
    }
    return {};
}*/

CommandPtr Parser::parse(std::string input){
    Tokens tokens = tokenize();
    std::string command = determine_command(tokens);
    /*std::variant<std::string, int, void> item_name = determine_operands(tokens, "-item");
    std::variant<std::string, int, void> top_left = determine_operands(tokens, "-top_left");
    std::variant<std::string, int, void> item_name = determine_operands(tokens, "-item");
    std::variant<std::string, int, void> width = determine_operands(tokens, "-width");
    std::variant<std::string, int, void> height = determine_operands(tokens, "-height");
    std::variant<std::string, int, void> id = determine_operands(tokens, "-id");
    const auto command = registry[command].makeCommand(...);
*/
    std::map<std::string, std::string> operands_map;
    for(auto i = 0; i < tokens.size() - 1 ; i += 2){
        operands_map[tokens[i]] = tokens[i+1];
    }
    auto cmdFACTORY = command_factory.create_command_builder(command, operands_map);
    return cmdFACTORY->get_result();
}

