#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

#include "tokenizer.hpp"
#include "../Command/i_command.hpp"

namespace pwpt
{

namespace Command
{

class Parser
{
public:
	pwpt::ICommandPtr Parse(std::istream& sInput);

private:
	Tokenizer	tokenizer;
};

} // namespace Command

} // namespace pwpt

#endif // _POWERPOINT_PARSER_HPP