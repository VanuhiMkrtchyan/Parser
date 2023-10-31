#include "item_factory.hpp"


ItemPtr ItemBuilderFactory::create_item(std::string item_name){
    if(item_name == "rectangle"){
        return std::make_unique<Rectangle>();
    }
}

