#include "tokenizer.hpp"

namespace pwpt
{
namespace Command
{

Tokenizer::Tokenizer()
{
}

SToken Tokenizer::NextToken(std::istream& sInput)
{
    std::string sLexemme = m_oLexer.NextLexemme(sInput);
    
    SToken sToken;
    if (IsPunct(sLexemme))
    {
        sToken.eType = ETokenType::Punct;
        sToken.cPunct = sLexemme[0];
    }
    else if (IsNumber(sLexemme))
    {
        sToken.eType = ETokenType::Number;
        sToken.iNumber = std::stoi(sLexemme);
    }
    else if (IsWord(sLexemme))
    {
        sToken.eType = ETokenType::Word;
        sToken.sWord = sLexemme;
    }
    return sToken;
}

bool Tokenizer::IsPunct(std::string const& sLexemme) const
{
    return sLexemme.size() == 1 && ispunct(sLexemme[0]);
}

bool Tokenizer::IsNumber(std::string const& sLexemme) const
{
    bool bIsNumber = true;

    if (sLexemme[0] < '1' || sLexemme[0] > '9')
        return false;

    for (auto const& c : sLexemme)
    {
        if (!std::isdigit(c))
        {
            bIsNumber = false;
            break;
        }
    }
    
    return bIsNumber;
}

bool Tokenizer::IsWord(std::string const& sLexemme) const
{
    bool bIsWord = true;

    for (auto const& c : sLexemme)
    {
        if (!isalpha(c) && c != '-')
        {
            bIsWord = false;
            break;
        }
    }

    return bIsWord;
}

}

}