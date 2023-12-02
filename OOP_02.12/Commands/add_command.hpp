#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP


#include "command.hpp"
#include "../Document/document.hpp"
#include "../Document/slide.hpp"
#include "../Items/item.hpp"
#include "../Item_Registry/item_registry.hpp"

class Add_Command : public Command{
    public:
        Add_Command(std::shared_ptr<Document>);
        std::string execute() override;
        CommandPtr clone() const override;
        void set_item(std::unique_ptr<Item>);
        void set_type(Item::Type);
    private:
        std::unique_ptr<Item> curr_item;
        Item::Type type_;
        std::shared_ptr<Document> document_;
};
#endif //ADD_COMMAND_HPP