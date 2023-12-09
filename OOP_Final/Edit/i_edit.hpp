#ifndef INTERFACE_IEdit_HPP
#define INTERFACE_IEdit_HPP

#include <iostream>
#include <memory>

#include <QObject>

#include "../Action/i_action.hpp"

namespace pwpt
{

class IEdit : public QObject
{
	Q_OBJECT

public:
	virtual void Do(IAction_SPtr&) = 0;

public slots:
	virtual void onActionCreated(IAction_SPtr&) = 0;

};
using IEdit_SPtr = std::shared_ptr<class IEdit>;
using IEdit_UPtr = std::unique_ptr<class IEdit>;

} // namespace pwpt

#endif // EDITOR_HPP_