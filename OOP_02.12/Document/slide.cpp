#include "slide.hpp"

Slide::Slide(const Slide& other)
{
    id_ = other.id_;
    numberOfItems = other.numberOfItems;
    name = other.name;
    for(auto& item : other.items){
        items.push_back(item->clone());
    }
}

Slide::Slide()
{
    id_= slide_count++;
}

Slide::Slide(Slide &&other)
{
    id_ = other.id_;
    numberOfItems = other.numberOfItems;
    name = other.name;
    items = std::move(other.items);
}

Slide& Slide::operator=(Slide other)
{
    swap(other);
    return *this;
}

void Slide::swap(Slide& other) noexcept {    
    std::swap(id_,other.id_);
    std::swap(numberOfItems,other.numberOfItems);
    std::swap(name,other.name);
    std::swap(items, other.items);
}


void Slide::display_content() const
{
    std::cout << "displaying all items in slide, with their properties" << std::endl;
}

void Slide::accept(I_Serializer &serializer)
{
    serializer.visit(name);
    serializer.visit(id_);
    serializer.visit(numberOfItems);
    items.resize(numberOfItems);
    for(auto& item: items){
        if(!item){
            Item::Type t;
            serializer.visit(t);
            
        }
        serializer.visit(item);
    }
}

void Slide::add_item(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
    ++numberOfItems;
}

void Slide::remove_item(int id){
    items.erase(std::next(items.begin(),id));
    --numberOfItems;
}
