#ifndef EDITOR_HPP_
#define EDITOR_HPP_

#include <iostream>
#include <memory>
#include <stack>

#include "../Edit/i_edit.hpp"

namespace pwpt
{

class Edit : public IEdit
{
public:
	void Do(IAction_SPtr&) override;

public slots:
	void onActionCreated(IAction_SPtr&) override;

private:
	void SendToRedoStack(IAction_SPtr const&);
	void SendToUndoStack(IAction_SPtr const&);

private:
	std::stack<IAction_SPtr> m_aForUndoActions;
	std::stack<IAction_SPtr> m_aForRedoActions;
};

} // namespace pwpt

#endif // EDITOR_HPP