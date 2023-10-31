//#include <QApplication>
#include <string>

#include "controller.hpp"
#include "../IO_stream/io_stream.hpp"
#include "../Parser/command_parser.hpp"
#include <memory>

void Controller::run(int argc, char* argv[]){
    std::string input_stream = IO_Stream::get_input();
    CommandPtr command = command_parser.parse(input_stream);
    command -> execute();
}