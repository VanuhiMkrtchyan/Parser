#include "serialize.hpp"



void Serializer::visit(double& val)
{
    I_Serializer::result  << val << " ";
}

void Serializer::visit(std::size_t & val)
{
    result << val << " ";
}

void Serializer::visit(Item::Coord& val)
{
    result << val.x <<  " " << val.y << " ";
}

void Serializer::visit(std::string&& val)
{
    result << val << " ";
}

void Serializer::visit(std::string& val)
{
    result << "\n" << val << " ";
}

void Serializer::visit(Item::Type& type)
{
    result << static_cast<std::size_t>(type) << " ";
}

void Serializer::visit(std::unique_ptr<Item>& val)
{
    result << "\n";
    val->accept(*this);
}

void Serializer::visit(std::vector<Slide>& slides)
{
    for(auto& slide : slides){
        slide.accept(*this);
    }
}


void Serializer::visit(Slide& val)
{
    result << "\n";
    val.accept(*this);
}

void Serializer::visit(Document& val)
{
    result << "\n";
    val.accept(*this);
}