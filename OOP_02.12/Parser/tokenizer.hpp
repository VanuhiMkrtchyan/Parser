#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

class Tokenizer{
    public:
        using Token = std::string;
        using Tokens = std::vector<std::string>;
    public:
        Tokens tokenize(std::string) const;
        std::string get_token(std::string, std::size_t) const;

};

#endif //TOKENIZER_HPP