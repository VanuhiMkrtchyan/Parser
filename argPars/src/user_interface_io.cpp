#include <iostream>


#include "../hpp/user_interface_io.hpp"

std::string User_Interface_IO::getInput(){
    std::string input;
    std::getline(std::cin , input);
    return input;
}

void User_Interface_IO::displayOutput(const double& result){
    std::cout << result << std::endl;
}
