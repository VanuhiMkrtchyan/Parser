#ifndef INTERFACE_ACTION_HPP
#define INTERFACE_ACTION_HPP

#include <exception>
#include <memory>
#include <string>

namespace pwpt
{

class IAction;
using ActionPtr = std::shared_ptr<class IAction>;

class IAction 
{
public:
	virtual void Run() = 0;
	virtual bool CanRun() const = 0;

	virtual ActionPtr Reverse() const = 0;
};


} 

#endif // INTERFACE_ACTION_HPP