#include "../Action/act_undo.hpp"
#include "undo_command.hpp"

namespace pwpt
{
//////////////////////////////////////////////////////////////////////
namespace Command
{ 

Undo_Command::Undo_Command()
{}

void Undo_Command::Execute()
{
	ActionPtr pAddSlide = std::make_shared<Undo_Command>();
    CreatedAction(pAddSlide);
}

ICommandPtr Undo_Command::Clone() const
{
	return std::make_shared<Undo_Command>(*this);
}

bool Undo_Command::MainOptionRequired() const
{
	return false;
}

size_t Undo_Command::RequiredMinOptionsCount() const
{
	return 0;
}

bool Undo_Command::Acceptarg(std::string const& Option, std::any Value)
{
	return false;
}

bool Undo_Command::Validate() const
{
	return true;
}

} 

} 