#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>
#include <vector>
#include <string>

#include "../Document/document_interface.hpp"
#include "../Document/slide_interface.hpp"

class Command{
    private:
        std::vector<std::string> _arguments;
        
    public:
        virtual ~Command() = default;
        using CommandPtr = std::unique_ptr<Command>;
        virtual void execute(I_Document&) = 0;
        virtual CommandPtr clone() const = 0;
        std::vector<std::string> get_arguments(){
            return _arguments;
        }
        void set_arguments(const std::vector<std::string>& args){
            _arguments = std::move(args);
        }
};

using CommandPtr = std::unique_ptr<Command>;

#endif //COMMAND_HPP