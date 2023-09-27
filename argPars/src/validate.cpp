#include <algorithm>

#include "../hpp/command_registry.hpp"
#include "../hpp/parser.hpp"

void Parser::Validate_command(TokensType token){
    std::string cmd = token.front();
    CommandRegistry cmdr;
    auto begin = cmdr.command_registry.begin();
	auto end = cmdr.command_registry.end();
    if (cmdr.command_registry.find(cmd) == end)
    {
        throw std::invalid_argument("Wrong command");
    }   
}

void Parser::Validate_operators(TokensType token){
    std::vector<std::string> command_values;
    auto tbegin = token.begin();
    auto tend = token.end();
    while(true){
        auto op = std::find(tbegin, tend, "-op");
        if(op == token.end()){
            break;
        }
        if(std::next(op) == token.end()){
            throw std::invalid_argument("Invalid operators");
        }
        command_values.push_back(*std::next(op));
        tbegin += 2;

    }
    for(auto str : command_values)
    Validate_values(command_values);
}


void Parser::Validate_values(TokensType /*token*/ value_vector){
    if(value_vector.size() < 2){
        throw std::invalid_argument("Invalid values, the count is not enough");
    }
    for(auto value : value_vector){
        try
		{
			double temp = std::stod(value);
		}
        catch(...){
            throw std::invalid_argument("Invalid argument");
        }
    }

}

// using CommandRegistry = std::unordered_map<std::string, Command*> registry;
// registry["add"] = new AddCommand;
// const auto iter = registry.find(command);
// if(iter == registry.end()) 
//      throw runtime_error("no command found");