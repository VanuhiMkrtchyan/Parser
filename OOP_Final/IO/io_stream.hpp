#ifndef IO_STREAM_HPP
#define IO_STREAM_HPP

#include <iostream>
#include <sstream>

#include "io_interface.hpp"

class IO_Stream : public IO_Interface{
    public:
        std::string get_input() override;
        void display_output(std::string) override;
};

#endif //IO_STREAM_HPP