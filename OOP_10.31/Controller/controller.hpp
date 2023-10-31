#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include "controller.hpp"
#include "../Controller/controller.hpp"
#include "../Parser/command_parser.hpp"

class Controller{
    public:
        Controller(){};
        void run(int argc, char* argv[]);
    private:
        Parser command_parser;
};


#endif //CONTROLLER_HPP