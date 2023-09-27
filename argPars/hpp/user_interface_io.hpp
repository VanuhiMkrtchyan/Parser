#ifndef USER_INTERFACE_IO_HPP
#define USER_INTERFACE_IO_HPP

#include <string>

#include "user_interface.hpp"

class User_Interface_IO : public User_Interface
{
    public:
        User_Interface_IO() {};
        
    public:
        std::string getInput() override;
        void displayOutput(const double& msg);
    private:
        std::string input;
};

#endif //USER_INTERFACE_IO_HPP
