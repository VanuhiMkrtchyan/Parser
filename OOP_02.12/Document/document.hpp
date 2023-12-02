#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "slide.hpp"


class Document
{
public:
    Document();

public:
    void add_slide(const Slide& slide);
    void add_slide(Slide&& slide);
    void remove_slide(Slide slide);
    void remove_slide(int id);
    void accept(I_Serializer&);

public:
    Slide& get_current_slide();
    void display_content() const;
    void display_slide_content(int id) const;


private:
    std::string name = "document";
    std::vector<Slide> slides;
    std::size_t numberOfSlides{0};
    int curr_slide_id;
};

#endif //DOCUMENT_HPP