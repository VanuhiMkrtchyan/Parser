#ifndef COMMAND_FACTORY_REGISTRY_HPP
#define COMMAND_FACTORY_REGISTRY_HPP

#include <map>
#include <memory>
#include <string>

#include "command_factory.hpp"
#include "../Document/document.hpp"

class Command_Factory_Registry{
    public:
        Command_Factory_Registry(std::shared_ptr<Document> doc);
        //std::unique_ptr<Command_Factory> find_factory(const std::string& );
        CommandFactoryPtr& operator[](const std::string&);
    private:
        std::map<std::string, CommandFactoryPtr> c_registry;
        std::shared_ptr<Document> c_doc{nullptr};
};


#endif //COMMAND_FACTORY_REGISTRY_HPP