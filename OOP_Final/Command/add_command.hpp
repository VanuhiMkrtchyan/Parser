#ifndef COMMAND_ADD_HPP_
#define COMMAND_ADD_HPP_

#include "i_command.hpp"

namespace pwpt
{

namespace Command
{ 

class Add_Command : public ICommand
{
public:
	CAddCmd();

	void Execute() override;
	ICommandPtr Clone() const override;

	bool MainOptionRequired() const override;
	size_t RequiredMinOptionsCount() const override;

	bool Acceptarg(std::string const&, std::any oValue) override;
	bool Validate() const override;
};

}

} 

#endif //COMMAND_ADD_HPP_