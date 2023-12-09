#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <map>
#include <string>


namespace pwpt
{
namespace Command
{



class Tokenizer
{
public:
	Tokenizer();

	Tokenizer(Tokenizer const&) = delete;
	Tokenizer& operator=(Tokenizer const&) = delete;

	SToken NextToken(std::istream& sInput);

private:
	bool IsPunct(std::string const&) const;
	bool IsNumber(std::string const&) const;
	bool IsWord(std::string const&) const;

private:
	std::map<std::string, EOperation>	m_oOperationTranslater;
	std::map<std::string, EOption>		m_oOptionTranslater;
	std::map<std::string, EPunct>		m_oPunctTranslater;
};
}
}

#endif // TOKENIZER_HPP