#include "deserialize.hpp"


void Deserializer::visit(Document &val)
{
    val.accept(*this);
}


void Deserializer::visit(double& val) 
{
    result >> val;
}

void Deserializer::visit(std::size_t &val)
{
    result >> val;
}

void Deserializer::visit(Item::Coord& val) 
{
    result >> val.x >> val.y;
}

void Deserializer::visit(std::string&& val) 
{
    // empty
}

void Deserializer::visit(std::string& val) 
{
    result >> val;
    m_lastToken = val;
}

void Deserializer::visit(Item::Type &type)
{
    static char twice{2};
    std::size_t t;
    auto pos = result.tellg();
    result >> t;
    if(--twice){
        result.seekg(pos);
    }
    else{
        twice = 2;
    }
    type = static_cast<Item::Type>(t);
    m_last_type = type;
}

void Deserializer::visit(std::unique_ptr<Item>& val) 
{
    /// TODO:
    switch (m_last_type){
        case Item::Type::Rect:
            val = std::make_unique<Rect>();
            break;
        default:
            break;
    }
    val->accept(*this);
}

void Deserializer::visit(Slide& val) 
{
    val.accept(*this);
}

void Deserializer::visit(std::vector<Slide>& slides)
{
    
    for(auto& slide : slides){
        slide.accept(*this);
    }
}