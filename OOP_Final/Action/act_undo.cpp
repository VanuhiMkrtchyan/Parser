#include "act_undo.hpp"

namespace pwpt
{

void Undo::Run()
{
	if (UndoStack->empty())
		throw CActionExecException{ "For now <undo> action cannot be used" };

	auto pAction = UndoStack->top();
	UndoStack->pop();

	auto pReverseAction = pAction->Reverse();

	if (pReverseAction->CanRun())
	{
		pReverseAction->Run();

		RedoStack->push(pReverseAction);
	}
	else
		throw CActionExecException{ "Unexpected error occurred!!!" };
}

bool Undo::CanRun() const
{
	return UndoStack != nullptr && !UndoStack->empty() &&
		   RedoStack != nullptr;
}

ActionPtr Undo::Reverse() const
{
	throw CActionExecException{ "Be Carefull, please!. You can't reverse <undo> action" };
}

void Undo::ProvideUndoRedoStacks(std::stack<ActionPtr>* pUndoStack, std::stack<ActionPtr>* pRedoStack)
{
	UndoStack = pUndoStack;
	RedoStack = pRedoStack;
}

}