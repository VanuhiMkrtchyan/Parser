#include "document.hpp"

#include <memory>
#include <string>

Document::Document() : current_slide_ID(0)
{
    slides.push_back(std::make_unique<Slide>());
    current_slide = slides[current_slide_ID];
}

SlidePtr Document::get_current_slide(){
    return slides[current_slide_ID];
}

void Document::set_current_slide(int ID){
    current_slide_ID = ID;
    current_slide = slides[current_slide_ID];
}

SlideVector& Document::get_slides(){
    return slides;
}

int Document::get_current_slide_id(){
    return current_slide_ID;
}

std::string Document::display_current_slide(){
    return current_slide->get_all_items();
}

std::string Document::display_slide_item(int ID){
    return current_slide->get_item_byID(ID)->info();
}

std::string Document::display_all_slides(){
    std::string result;
    int slide_ID;
    for(auto& slide : slides){
        result = "slide  " + std::to_string(slide_ID) + "\n";
        result += slide->get_all_items();
        slide_ID++;
    }
    return result;
}
