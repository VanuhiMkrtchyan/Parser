
#ifndef _POWERPOINT_ACTION_UNDO_HPP_
#define _POWERPOINT_ACTION_UNDO_HPP_

#include <stack>

#include "i_action.hpp"
#include "pwpt_islidecontainer.h"

namespace pwpt
{

class Undo : public IAction 
{
public:
	Undo() =default;

	void Run() override;
	bool CanRun() const override;

	ActionPtr Reverse() const override;

	// Own interface
	void ProvideUndoRedoStacks(std::stack<ActionPtr>* pUndoStack, std::stack<ActionPtr>* pRedoStack);

private:
	std::stack<ActionPtr>* UndoStack = nullptr;
	std::stack<ActionPtr>* RedoStack = nullptr;
};

} // namespace pwpt

#endif // _POWERPOINT_ACTION_UNDO_HPP_