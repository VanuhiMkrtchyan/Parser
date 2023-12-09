#include "act_redo.hpp"

namespace pwpt
{

void Redo::Run()
{
	if (RedoStack == nullptr || RedoStack->empty())
		throw CActionExecException{ "For now <redo> action cannot be used" };

	auto pAction = RedoStack->top();
	RedoStack->pop();

	auto pReverseAction = pAction->Reverse();

	if (pReverseAction->CanRun())
	{
		pReverseAction->Run();

		UndoStack->push(pReverseAction);
	}
	else
		throw CActionExecException{ "Unexpected error occurred!!!" };
}

bool Redo::CanRun() const
{
	return RedoStack != nullptr && !RedoStack->empty() &&
		   UndoStack != nullptr;
}

ActionPtr Redo::Reverse() const
{
	throw CActionExecException{ "Be Carefull, please!. You can't reverse <redo> action" };
}

void Redo::ProvideUndoRedoStacks(std::stack<ActionPtr>* pUndoStack, std::stack<ActionPtr>* pRedoStack)
{
	UndoStack = pUndoStack;
	RedoStack = pRedoStack;
}

}