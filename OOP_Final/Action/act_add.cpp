#include "act_add.hpp"
#include "act_delete.hpp"
#include "../App/app_manager.hpp"
#include "../Doc/i_slide.hpp"

namespace pwpt
{

Add_Slide::Add_Slide(int iPositionInSlideshow)
	: slide{ nullptr }
	, slide_show{ nullptr }
	, slide_index{ iPositionInSlideshow }
{}

void Add_Slide::Run()
{
	if(slide == nullptr)
		slide = std::make_shared<CSlide>();
	
	auto pDoc = App::CAppManager::AppInstance().GetDocument();
	
	if (slide_index == 0)
	{
		slide_show->Add(slide);
		pDoc->SetActiveSlide(1);
		slide_index = 1;
	}
	else
	{
		slide_show->Insert(slide, slide_index);
	}
	
}

bool Add_Slide::CanRun() const
{
	auto pDoc = App::CAppManager::AppInstance().GetDocument();
	if (pDoc == nullptr)
		return false;

	slide_show = pDoc->GetSlideShow();

	return (slide_index >= 0) && (slide_show != nullptr);
}

ActionPtr Add_Slide::Reverse() const
{
	ActionPtr pActReverse = std::make_shared<CDeleteSlide>(slide_index);

	return pActReverse;
}

} // namespace pwpt