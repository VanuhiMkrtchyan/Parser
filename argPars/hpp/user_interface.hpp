#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <string>
class User_Interface{
    public: 
        virtual std::string getInput() = 0;
        virtual void displayOutput(const double& result) = 0;
        //virtual void displayMessage(const std::string& msg) = 0;
};

#endif //USER_INTERFACE_HPP