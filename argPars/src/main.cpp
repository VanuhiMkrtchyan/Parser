#include "../hpp/controller.hpp"
#include "../hpp/user_interface.hpp"
#include "../hpp/user_interface_io.hpp"

#include <memory>

int main(){
    std::unique_ptr<User_Interface> user = std::make_unique<User_Interface_IO>();
    std::unique_ptr<Parser> parser = std::make_unique<Parser>();
    Controller controller(std::move(user), std::move(parser));
    //Controller controller;
    controller.run();
}
