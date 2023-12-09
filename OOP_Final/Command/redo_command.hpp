#ifndef _POWERPOINT_COMMAND_REDO_HPP_
#define _POWERPOINT_COMMAND_REDO_HPP_

#include "i_command.hpp"

namespace pwpt
{

namespace Command
{


class Redo_Command : public ICommand
{
public:
	Redo_Command(){}
	Redo_Command(Redo_Command const&) = default;

	void Execute() override;
	ICommandPtr Clone() const override;

	bool MainOptionRequired() const override;
	size_t RequiredMinOptionsCount() const override;

	bool Acceptarg(std::string const&, std::any oValue) override;
	bool Validate() const override;
};
} 

} 

#endif // COMMAND_REDO_HPP