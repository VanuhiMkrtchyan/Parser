#include "../hpp/command_registry.hpp"

CommandRegistry::CommandRegistry(){
    command_registry["Add"] = new AddCommand();
    command_registry["Sub"] = new SubCommand();
    command_registry["Mul"] = new MulCommand();
    command_registry["Div"] = new DivCommand();
    command_registry["Exit"] = new Exit();
    command_registry["Help"] = new Help();
   // command_registry["Square"] = new Square();
}

CommandRegistry::~CommandRegistry(){
	for (auto cmd: command_registry)
	{
		delete cmd.second;
	}
}

bool CommandRegistry::comand_exists(const std::string cmd){
    auto command = command_registry.find(cmd);
    return command != command_registry.end();
}

Command* const CommandRegistry::operator[](const std::string cmd)
{
    return command_registry[cmd];
}
