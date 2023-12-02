#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>
#include <vector>
#include <string>

#include "../Items/item.hpp"
#include "../Parser/tokenizer.hpp"

class Command{
    public:
        using CommandPtr = std::unique_ptr<Command>;
    protected:
        std::vector<std::string> arguments_;
    public:
        virtual std::string execute() = 0;
        virtual CommandPtr clone() const = 0;
        /*void set_arguments(const std::vector<std::string>& args){
            arguments_ = std::move(args);
        }*/
        virtual ~Command() = default;
};

#endif //COMMAND_HPP