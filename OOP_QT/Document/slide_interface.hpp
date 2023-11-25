#ifndef SLIDE_INTERFACE_HPP
#define SLIDE_INTERFACE_HPP

#include "../Items/item.hpp"

class I_Slide{
    public:
        virtual void add_item(ItemPtr) = 0;
        virtual void change_item(int ID) = 0;
        virtual void remove_item(int ID) = 0;
        virtual std::string get_all_items() = 0;
        virtual ItemPtr get_item_byID(int ID) = 0;
};

using SlidePtr = std::unique_ptr<I_Slide>;

#endif //SLIDE_INTERFACE_HPP