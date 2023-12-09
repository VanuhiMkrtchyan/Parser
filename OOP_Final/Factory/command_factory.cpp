#include "command_factory.hpp"
#include "../Command/add_command.hpp"
#include "../Command/redo_command.hpp"
#include "../Command/undo_command.hpp"

namespace pwpt
{

namespace Command
{

Command_Factory::Command_Factory()
{
	pwpt::ICommand_SPtr pAdd	= std::make_shared<CAddCmd>();
	pwpt::ICommand_SPtr pRedo	= std::make_shared<CRedoCmd>();
	pwpt::ICommand_SPtr pUndo	= std::make_shared<CUndoCmd>();

	m_aCommands.emplace("add",		pAdd);
	m_aCommands.emplace("redo",		pRedo);
	m_aCommands.emplace("undo",		pUndo);
}

Command_Factory& Command_Factory::GetInstance()
{
	static Command_Factory oInstance{};

	return oInstance;
}

ICommand_SPtr Command_Factory::CreateCommand(std::string sCmd) const
{
	ICommand_SPtr pCommand = nullptr;

	if (m_aCommands.count(sCmd))
		pCommand = m_aCommands.at(sCmd)->Clone();

	return pCommand;
}

} // namespace Command

} // namespace pwpt