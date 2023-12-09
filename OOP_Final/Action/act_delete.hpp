#include "i_action.hpp"
#include "../Doc/i_slide.hpp"
#include "pwpt_islidecontainer.h"

namespace pwpt
{

class Delete_Slide : public IAction 
{
public:
	explicit Delete_Slide(int iPositionInSlide = 0);

	void Run() override;
	bool CanRun() const override;

	ActionPtr Reverse() const override;

	void SetWorkingSlide(ISlideContainer_SPtr);

private:
	SlidePtr m_pSlide = nullptr;
	SlideContainerPtr mutable slide_show	= nullptr;
	int	pos_slide;
};

} // namespace pwpt