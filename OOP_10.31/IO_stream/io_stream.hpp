#ifndef IO_STREAM_HPP
#define IO_STREAM_HPP

#include <iostream>
#include <string>

class IO_Stream{
    public:
        static std::string get_input();
        static void display_output();
};

#endif //IO_STREAM_HPP