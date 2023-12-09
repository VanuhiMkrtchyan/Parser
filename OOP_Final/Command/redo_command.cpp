#include "act_redo.hpp"
#include "redo_command.hpp"

namespace pwpt
{
//////////////////////////////////////////////////////////////////////
namespace Command
{ 

void Redo_Command::Execute()
{
	ActionPtr add_slide = std::make_shared<Redo_Command>();

	if (pAddSlide != nullptr)
		emit CreatedAction(pAddSlide);
}

ICommandPtr Redo_Command::Clone() const
{
	return std::make_shared<Redo_Command>(*this);
}

bool Redo_Command::MainOptionRequired() const
{
	return false;
}

size_t Redo_Command::RequiredMinOptionsCount() const
{
	return 0;
}

bool Redo_Command::Acceptarg(std::string const& sOption, std::any oValue)
{
	return false;
}

bool Redo_Command::Validate() const
{
	return true;
}

} 

} 