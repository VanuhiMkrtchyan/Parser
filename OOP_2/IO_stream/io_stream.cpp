#include "io_stream.hpp"

std::string IO_Stream::get_input(){
    std::string input;
    std::getline(std::cin , input);
    return input;
}

void IO_Stream::display_output(){
    std::cout << "Display output" << std::endl;
}