#include "io_stream.hpp"

#include <sstream>

std::string IO_Stream::get_input(){
    std::cout << "Get input" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void IO_Stream::display_output(std::string out){
    std::cout << "Display output" << out << std::endl;
}