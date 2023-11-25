#ifndef DOCUMENT_INTERFACE_HPP
#define DOCUMENT_INTERFACE_HPP

#include "slide_interface.hpp"

#include <vector>

using SlideVector = std::vector<SlidePtr>;

class I_Document{
    public:
        virtual SlidePtr get_current_slide() = 0;
        virtual void set_current_slide(int ID) = 0;
        virtual SlideVector& get_slides() = 0;
        virtual int get_current_slide_id() = 0;
        virtual std::string display_current_slide() = 0;
        virtual std::string display_slide_item(int ID) = 0;
        virtual std::string display_all_slides() = 0;

};

#endif //DOCUMENT_INTERFACE_HPP