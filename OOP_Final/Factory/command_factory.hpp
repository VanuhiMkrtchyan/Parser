#ifndef COMMAND_FACTORY_HPP_
#define COMMAND_FACTORY_HPP_

#include <unordered_map>

#include "../Command/i_command.hpp"

namespace pwpt
{

namespace Command
{

class Command_Factory
{
public:
	Command_Factory(Command_Factory const&) = delete;
	Command_Factory& operator=(Command_Factory const&) = delete;

	static Command_Factory& GetInstance();

	pwpt::ICommand_SPtr CreateCommand(std::string) const;

private:
	Command_Factory();

private:
	std::unordered_map<std::string, pwpt::ICommand_SPtr> m_aCommands;
};

} // namespace Command

} // namespace pwpt

#endif // COMMAND_FACTORY_HPP_