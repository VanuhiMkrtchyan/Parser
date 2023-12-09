#include "edit.hpp"
#include "../Action/act_redo.hpp"
#include "../Action/act_undo.hpp"

namespace pwpt
{

void Edit::Do(IAction_SPtr& pAction)
{
	if (pAction->CanRun())
	{
		pAction->Run();
	}
}

void Edit::onActionCreated(IAction_SPtr& pAction)
{
	auto pUndo = std::dynamic_pointer_cast<CUndo>(pAction);
	auto pRedo = std::dynamic_pointer_cast<CRedo>(pAction);

	if (pUndo != nullptr)
	{
		pUndo->ProvideUndoRedoStacks(&m_aForUndoActions, &m_aForRedoActions);

		if (pUndo->CanRun())
		{
			pUndo->Run();
		}
	}
	else if (pRedo != nullptr)
	{
		pRedo->ProvideUndoRedoStacks(&m_aForUndoActions, &m_aForRedoActions);

		if (pRedo->CanRun())
		{
			pRedo->Run();
		}
	}
	else
	{
		Do(pAction);

		SendToUndoStack(pAction);
	}
}

void Edit::SendToUndoStack(IAction_SPtr const& pAction)
{
	m_aForUndoActions.push(pAction);
}

void Edit::SendToRedoStack(IAction_SPtr const& pAction)
{
	m_aForRedoActions.push(pAction);
}

} // namespace pwpt