#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include "../Parser/command_parser.hpp"
#include "../Document/document.hpp"

class Controller{
    public:
        Controller(){};
        void run(int argc, char* argv[]);
    private:
        Parser command_parser;
        Document doc;
};


#endif //CONTROLLER_HPP