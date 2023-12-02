#ifndef I_SERIALIZE_HPP
#define I_SERIALIZE_HPP

#include <string>
#include <vector>
#include <sstream>

class Item;
class Slide;
class Document;

#include "../Items/item.hpp"
#include "../Items/rectangle.hpp"
#include "../Document/document.hpp"
#include "../Document/slide.hpp"


class I_Serializer
{
    public:
        virtual void visit(double& val) = 0;
        virtual void visit(std::size_t& val) = 0;
        virtual void visit(std::string& val) = 0;
        virtual void visit(std::string&& val) = 0;
        virtual void visit(std::vector<Slide>& slides) = 0;
        virtual void visit(std::unique_ptr<Item>& item) = 0;
        virtual void visit(Item::Coord& point) = 0;
        virtual void visit(Slide& slide) = 0;
        virtual void visit(Item::Type& type) = 0;
        virtual void visit(Document& circle) = 0;

    public:
        auto stealResult() { return std::move(result); }
        void setStream(std::stringstream stream) { result = std::move(stream); }

    protected:
        std::stringstream result;
};

#endif //I_SERIALIZE_HPP