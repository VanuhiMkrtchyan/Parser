//#include <QApplication>

#include <string>

#include "controller.hpp"
#include "../IO_stream/io_stream.hpp"
#include "../Parser/command_parser.hpp"

void Controller::run(int argc, char* argv[]){
    std::string input_stream = get_input();
    CommandPtr command = parser.parse(input_stream);
    command -> execute();
}