#include "command_factory_registry.hpp"
#include "add_command_factory.hpp"

Command_Factory_Registry::Command_Factory_Registry(std::shared_ptr<Document> doc){
    c_registry["add"] = std::make_unique<Add_Command_Factory>(doc);
}

CommandFactoryPtr& Command_Factory_Registry::operator[](const std::string& cmd){
    return c_registry.at(cmd);
}
/*std::unique_ptr<Command_Factory> Command_Factory_Registry::find_factory(const std::string& name){
    auto& factory = c_registry.at(name);
    return factory->clone();
}*/