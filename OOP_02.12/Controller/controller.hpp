#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include "../Document/document.hpp"
#include "../IO/io_stream.hpp"
#include "../Command_Factory/command_creator.hpp"
#include "../Parser/parser.hpp"

class Controller{
    public:
        Controller(Document doc): c_doc_{std::move(doc)}, cmd_factory_registry_{doc}{}
        void run();
    private:
        std::shared_ptr<Document> c_doc_;
        Command_Factory_Registry cmd_factory_registry_;
        Command_Parser parser_;
        Command_Creator command_creator;
};


#endif //CONTROLLER_HPP