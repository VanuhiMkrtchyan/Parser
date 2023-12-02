#include "document.hpp"

#include <memory>
#include <string>

#include "../Serialization/i_serialize.hpp"

Document::Document()
{
    add_slide(Slide{});
    curr_slide_id = 0;
}
void Document::accept(iSerializer &serial)
{ 
    serial.visit(name);
    serial.visit(numberOfSlides);
    slides.resize(numberOfSlides);

    for(auto& slide : slides){
        slide.accept(serial);
    }
}

void Document::display_content() const
{
    for(const auto& slide : slides){
        slide.display_content();
    }
}

void Document::display_slide_content(int id) const
{
    slides[id].display_content();
}

void Document::add_slide(Slide&& slide)
{
    ++curr_slide_id;
    ++numberOfSlides;
    slides.push_back(std::move(slide));
}

void Document::add_slide(const Slide& slide)
{

    ++curr_slide_id;
    ++numberOfSlides;
    slides.push_back(slide);
}


Slide &Document::get_current_slide()
{
    return slides[curr_slide_id];
}
