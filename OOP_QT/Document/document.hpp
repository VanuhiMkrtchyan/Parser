#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "document_interface.hpp"
#include "slide_interface.hpp"
#include "slide.hpp"

class Document : public I_Document{
    private:
        int current_slide_ID;
        SlidePtr current_slide;
        SlideVector slides;
    public:
        Document();
        SlidePtr get_current_slide() override;
        void set_current_slide(int ID) override;
        SlideVector& get_slides() override;
        int get_current_slide_id() override;
        std::string display_current_slide() override;
        std::string display_slide_item(int ID) override;
        std::string display_all_slides() override;
};

#endif //DOCUMENT_HPP