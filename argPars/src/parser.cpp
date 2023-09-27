#include "../hpp/parser.hpp"
#include "../hpp/command_registry.hpp"


TokensType Parser::tokenize(const std::string& input){
    TokensType Tokens;
    std::stringstream ss(input);
    if(ss.fail()){
        throw std::invalid_argument("Parser tokenization is failed");
    }
    std::string temp;
    while(std::getline(ss, temp, ' '))
    { 
        if(!temp.empty())
            Tokens.push_back(temp);
    }    
    return Tokens;
}

std::string Parser::make_command(const TokensType token, Op_Val_Pair_List& Op_Value_list){
    ///TODO: write only one try and one catch, 
    ///TODO:whole program masy be in ehile loop, and after catch make the bool false
    
    try{
        Validate_command(token);
        Validate_operators(token);        
        auto begin = token.begin() + 1;
        auto end = token.end();
        for(auto it = begin; it != end; it += 2){
            Op_Val_Pair tmp_pair(*it, std::stod(*(it+1)));
            Op_Value_list.push_back(tmp_pair);
        }
        std::string command = token.front();
        return command;
    }
    catch(...){
        std::cout << "No such command or wrong arguments " << std::endl;
    }
    return "";
}
