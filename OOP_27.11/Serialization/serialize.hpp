#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "../Document/document.hpp"
#include "../commandBuilder/command_builder.hpp"

class Serialazer{
    public:
        void save(Document& doc, const std::string file);
        void load(Document& doc, const std::string file);
};


#endif //SERIALIZE_HPP