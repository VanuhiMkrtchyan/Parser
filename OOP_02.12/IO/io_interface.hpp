#ifndef IO_INTERFACE_HPP
#define IO_INTERFACE_HPP

#include <string>
#include <vector>

class IO_Interface{
    public:
        virtual std::string get_input() = 0;
        virtual void display_output(std::string) = 0;
        virtual ~IO_Interface(){}
};

#endif //IO_INTERFACE_HPP