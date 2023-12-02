#include "tokenizer.hpp"
#include <sstream>

Tokenizer::Tokens Tokenizer::tokenize(std::string input) const {
    Token tmp;
    std::istringstream in(input);
    Tokens tokens;
    while(in >> tmp){
        tokens.push_back(tmp);
    }
    return tokens;
}

std::string Tokenizer::get_token(std::string str, std::size_t n) const{
    std::istringstream in(str);
    Token tmp;
    while( n > 0 && in >> tmp ){
        --n;
    }
    if(n == 0) { return tmp; }
    return "error";
}