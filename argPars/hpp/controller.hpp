#ifndef CONTROLER_HPP
#define CONTROLER_HPP


#include "command_registry.hpp"
#include "user_interface.hpp"
#include "user_interface_io.hpp"
#include "parser.hpp"
#include <memory>

class Controller{
    public:
        Controller()  = default;
        Controller(std::unique_ptr<User_Interface> u, std::unique_ptr<Parser> p)
        {
            user = std::move(u);
            parser = std::move(p);
            command_registry = std::make_unique<CommandRegistry>();
        };
        void run();
        ~Controller(){};
    private:
        std::unique_ptr<User_Interface> user;
        std::unique_ptr<Parser> parser;
        std::unique_ptr<CommandRegistry> command_registry;
};

#endif //CONTROLER_HPP