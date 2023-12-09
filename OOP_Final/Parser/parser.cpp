#include <iostream>

#include "../Command/i_command.hpp"
#include "../Factory/command_factory.hpp"
#include "parser.hpp"

namespace pwpt
{

namespace Command
{

pwpt::ICommandPtr Parser::Parse(std::istream& sInput)
{
	ICommandPtr pCommand = nullptr;
	
	SToken oToken = tokenizer.NextToken(sInput);

	if (oToken.eType != ETokenType::Word)
		return pCommand;

	pCommand = Command_Factory::GetInstance().CreateCommand(oToken.sWord);

	if (!pCommand->MainOptionRequired() )
	{
		if (!sInput.eof())
			throw std::logic_error{ "invalid command!!!\n" };

		return pCommand;
	}

	// Main option (starts with --)
	oToken = tokenizer.NextToken(sInput);
	if (oToken.eType != ETokenType::Word)
		throw std::logic_error{ "invalid command!!!\n" };

	bool bMainAccpeted = pCommand->AcceptMainOption(oToken.sWord);

	if (bMainAccpeted)
	{
		while (!sInput.eof())
		{
			oToken = tokenizer.NextToken(sInput);
			if (oToken.eType != ETokenType::Word)
				throw std::logic_error{ "invalid command!!!\n" };

			SToken oSecondToken;
			if(!sInput.eof())
				oSecondToken = tokenizer.NextToken(sInput);

			pCommand->Acceptarg(oToken.sWord, oSecondToken.GetValue());
		}
	}

	return pCommand;
}


} // namespace Command

} // namespace pwpt