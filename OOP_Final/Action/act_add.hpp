#include "i_action.hpp"
#include "../Doc/islide_container.hpp"

namespace pwpt
{

class Add_Slide : public IAction 
{
public:
	explicit Add_Slide(int);

	void Run() override;
	bool CanRun() const override;

	ActionPtr Reverse() const override;

private:
	SlidePtr slide = nullptr;
	SlideContainerPtr mutable slide_show = nullptr;
	int	slide_index;
};

} // namespace pwpt