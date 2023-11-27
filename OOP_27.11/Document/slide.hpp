#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <map>
#include <string>
#include <vector>
#include "slide_interface.hpp"

using ItemMap = std::map<int, ItemPtr>;

class Slide : public I_Slide{
    public:
        void add_item(ItemPtr) override;
        void change_item(int ID) override;
        void remove_item(int ID) override;
        std::string get_all_items() override;
        ItemPtr get_item_byID(int ID) override;
    private:
        ItemMap::iterator find_item(int ID);

    private:
        int item_id = 0;
        ItemMap items;
};

#endif //SLIDE_HPP