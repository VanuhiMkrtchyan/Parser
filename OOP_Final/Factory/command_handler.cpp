#include "../App/app_manager.hpp"
#include "command_handler.hpp"

namespace pwpt
{

Command_Handler::Command_Handler()
{}

void Command_Handler::Handle(ICommand_SPtr& pCommand)
{

	QObject::connect(pCommand.get(),  &Command::ICommand::CreatedAction, this, &IHandler::OnCommandCreatedAction);

	try
	{
		pCommand->Execute();
	}
	catch (std::exception const& ex) 
	{
		std::ostream* pOutput = App::CAppManager::AppInstance().GetOutputStreamDevice();
		*pOutput << ex.what();

	}

}

void Command_Handler::OnInputDetected(std::string const& sInput)
{
	std::stringstream sInputStream{ sInput };

	ICommand_SPtr pCmd = nullptr;
	std::ostream* pOutput = App::CAppManager::AppInstance().GetOutputStreamDevice();
	
	try
	{
		pCmd = m_oParser.Parse(sInputStream);
    }
	catch (std::exception const& ex)
	{
		*pOutput << ex.what();
	}
}

void Command_Handler::OnCommandCreatedAction(ActionPtr& pAction)
{
	emit ActionConstructed(pAction);
}

}