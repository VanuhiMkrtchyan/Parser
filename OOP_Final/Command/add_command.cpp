#include <string>

#include "../Action/act_add.hpp"
#include "add_command.hpp"
#include "../App/app_manager.hpp"

namespace pwpt
{

namespace Command
{ 

Add_Command::Add_Command()
{
	m_aAcceptedOptions = { "-slide" };
}

void Add_Command::Execute()
{
	auto& oApp = App::App_Manager::AppInstance();

	DocPtr pDoc = App::App_Manager::AppInstance().GetDocument();
	if (pDoc == nullptr)
		throw CCmdExecException{ "Application's document is invalid" };

	if (m_sMainOption == "-slide")
	{
		auto pSlideShow = pDoc->GetSlideShow();
		if (pSlideShow == nullptr)
			throw CCmdExecException{ "The slideshow is invalid!!!" };

		IAction_SPtr pAddSlide = nullptr;
		if (m_aOptValues.empty())
		{
			pAddSlide = std::make_shared<CAddSlide>();
		}
		else
		{
			if (m_aOptValues.contains("-index"))
			{
				int iSlideIndex = std::any_cast<int>(m_aOptValues["-index"]);

				pAddSlide = std::make_shared<CAddSlide>(iSlideIndex);
			}
		}

		if (pAddSlide != nullptr)
			emit CreatedAction(pAddSlide);

	}
}

ICommandPtr Add_Command::Clone() const
{
	return std::make_shared<Add_Command>(*this);
}

bool Add_Command::MainOptionRequired() const
{
	return true;
}

size_t Add_Command::RequiredMinOptionsCount() const
{
	return 0;
}

bool Add_Command::Acceptarg(std::string const& sOption, std::any oValue)
{
	bool bIsAcceptedOption = false;

	if (m_sMainOption.empty())
		return bIsAcceptedOption;

	try
	{
		if (m_sMainOption == "-slide")
		{
			if (sOption == "-index")
			{
				int iValue = std::any_cast<int>(oValue);
				
				m_aOptValues.emplace(sOption, iValue);
				bIsAcceptedOption = true;
				
			}
		}
	}
	catch (...)
	{
		bIsAcceptedOption = false;
	}
		
	return bIsAcceptedOption;
}

bool Add_Command::Validate() const
{
	return true;
}

} // namespace Command

} // namespace pwpt