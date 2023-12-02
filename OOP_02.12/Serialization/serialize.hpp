#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "i_serialize.hpp"
#include "../Items/item.hpp"
#include "../Items/rectangle.hpp"
#include "../Document/document.hpp"
#include "../Document/slide.hpp"

class Serialazer : public I_Serializer{
    public:
        void visit(double& val) override;
        void visit(std::size_t& val) override;
        void visit(std::string& val) override;
        void visit(std::string&& val) override;
        void visit(std::vector<Slide>& slides) override;
        void visit(std::unique_ptr<Item>& item) override;
        void visit(Item::Coord& point) override;
        void visit(Slide& slide) override;
        void visit(Item::Type& type) override;
        void visit(Document& circle) override;
};




#endif //SERIALIZE_HPP