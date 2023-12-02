#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <map>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include "../Items/item.hpp"

class Slide{
    public:
        Slide();
        Slide(std::size_t id) { id_ = id; }
        Slide(const Slide& );
        Slide& operator=(Slide);
        Slide(Slide&&);
    public:
        void swap(Slide&) noexcept ;
        void add_item(ItemPtr);
        void remove_item(int);
        auto get_id();
        void display_content() const ;
        void accept(I_Serializer&);

    private:
        std::string name{"slide"};
        std::size_t id_;
        std::size_t numberOfItems{0};
        std::list<std::unique_ptr<Item>> items;

        auto& count() { return slide_count; }

    private:
        inline static std::size_t slide_count{0};
};

using SlidePtr = std::shared_ptr<Slide>;


#endif //SLIDE_HPP