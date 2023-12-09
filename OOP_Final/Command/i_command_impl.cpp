#include "i_command.hpp"

namespace pwpt
{

namespace Command
{ 

ICommand::ICommand(ICommand const& oCommand)
{
	accept_options = oCommand.accept_options;
	main_option = oCommand.main_option;
	values = oCommand.values;
};

bool ICommand::AcceptMainOption(std::string const& Option)
{
	bool accepted = std::find(accept_options.begin(), accept_options.end(), Option) != accept_options.end();

	if (accepted)
		main_option = Option;

	return accepted;
}

}

} // namespace pwpt