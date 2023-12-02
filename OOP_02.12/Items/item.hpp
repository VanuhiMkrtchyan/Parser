#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../Serialization/i_serialize.hpp"

class Item {
    public:
        struct Coord{
            int x, y;
            Coord() = default;
            Coord(int x, int y) : x{x}, y{y}{}

        };
        virtual ~Item(){}
        enum class TYPE : std::size_t{
            Rect = 50
        };
    protected:
        TYPE type_;
    public:
        virtual void accept(I_Seriaklizer&) = 0;
        virtual std::unique_ptr<Item> clone() const = 0;
        TYPE type(){
            return type_;
        }
        
};

using ItemPtr = std::shared_ptr<Item>;

#endif //ITEM_HPP