#include "act_add.hpp"
#include "act_delete.hpp"
#include "pwpt_appmanager.h"

namespace pwpt
{

Delete_Slide::Delete_Slide(int iPositionInslide)
	: slide{ nullptr }
	, slide_show{ nullptr }
	, pos_slide{ iPositionInslide }
{}

void Delete_Slide::Run()
{
	slide = slide_show->GetSlide(pos_slide);

	slide_show->Remove(pos_slide);
}

bool Delete_Slide::CanRun() const
{
	auto pDoc = App::CAppManager::AppInstance().GetDocument();
	if (pDoc == nullptr)
		return false;

	slide_show = pDoc->Getslide_show();

	return pos_slide >= 0 && slide_show != nullptr;
}

ActionPtr Delete_Slide::Reverse() const
{
	ActionPtr pActReverse = std::make_shared<CAddSlide>(pos_slide);

	return pActReverse;
}

void Delete_Slide::SetWorkingslide_show(ISlideContainer_SPtr pslide_show)
{
	slide_show = pslide_show;
}

} // namespace pwpt