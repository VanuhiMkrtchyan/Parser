#include "application.hpp"

void Application::execute(){
    std::cout << "Starting execute" << std::endl;
    while(is_running){
        try{
            controller_.run();
        }
        catch(std::exception& e){
            io_.display_output(e.what());
        }
    }
}