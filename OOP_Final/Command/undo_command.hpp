#ifndef COMMAND_UNDO_HPP
#define COMMAND_UNDO_HPP

#include "i_command.hpp"

namespace pwpt
{

namespace Command
{ 

class Undo_Command : public ICommand
{
public:
	Undo_Command();
	Undo_Command(Undo_Command const&) = default;

	void Execute() override;
	ICommandPtr Clone() const override;

	bool MainOptionRequired() const override;
	size_t RequiredMinOptionsCount() const override;

	bool Acceptarg(std::string const&, std::any) override;
	bool Validate() const override;
};

} 
} 

#endif // COMMAND_UNDO_HPP