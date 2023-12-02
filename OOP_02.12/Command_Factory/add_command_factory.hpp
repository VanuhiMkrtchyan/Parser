#ifndef ADD_COMMAND_FACTORY_HPP
#define ADD_COMMAND_FACTORY_HPP

#include "command_factory.hpp"
#include "../Item_Registry/item_registry.hpp"

class Document;
class Slide;

class Add_Command_Factory : public Command_Factory{
    public:
        Add_Command_Factory(std::shared_ptr<Document> doc) : doc_{doc}{}
        std::unique_ptr<Command> create_command(const std::string&) override;
        std::unique_ptr<Command_Factory> clone() const override; 

        void set_document(std::shared_ptr<Document>);
        void set_slide(std::shared_ptr<Document>);
    private:
        std::shared_ptr<Document> doc_;
        Item_Registry item_registry_;
};

#endif //ADD_COMMAND_FACTORY_HPP