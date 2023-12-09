#ifndef COMMAND_HANDLER_HPP_
#define COMMAND_HANDLER_HPP_

#include "../Parser/parser.hpp"

namespace pwpt
{

class Command_Handler
{
public:
	Command_Handler();

	Command_Handler(Command_Handler const&) = delete;
	Command_Handler& operator=(Command_Handler const&) = delete;



	void Handle(ICommand_SPtr&) override;

public slots:
	void OnInputDetected(std::string const&) override;
	void OnCommandCreatedAction(ActionPtr&) override;

private:
	Command::CParser m_oParser;

};

} // namespace pwpt

#endif // COMMAND_HANDLER_HPP