#include "item_registry.hpp"


ItemRegistry::ItemRegistry(){
    //item_reg["circle"] = std::make_unique<Circle>();
    item_reg["rectangle"] = std::make_unique<Rectangle>();
    //item_reg["line"] = std::make_unique<Line>();
}