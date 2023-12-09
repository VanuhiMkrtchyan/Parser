#ifndef _POWERPOINT_ACTION_REDO_HPP_
#define _POWERPOINT_ACTION_REDO_HPP_

#include <stack>

#include "i_action.hpp"
#include "../Doc/islide_container.hpp"

namespace pwpt
{

class Redo : public IAction
{
public:
	Redo() =default;

	void Run() override;
	bool CanRun() const override;

	ActionPtr Reverse() const override;

	void ProvideUndoRedoStacks(std::stack<ActionPtr>* pUndoStack, std::stack<ActionPtr>* pRedoStack);

private:
	std::stack<ActionPtr>* UndoStack = nullptr;
	std::stack<ActionPtr>* RedoStack = nullptr;
};

} // namespace pwpt

#endif // _POWERPOINT_ACTION_REDO_HPP_