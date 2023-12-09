#ifndef INTERFACE_ICOMMAND_HPP_
#define INTERFACE_ICOMMAND_HPP_

#include <any>
#include <exception>
#include <memory>
#include <queue>

#include <QObject>

#include "../Action/i_action.hpp"

namespace pwpt
{

namespace Command
{ 
class ICommand : public QObject
{
	Q_OBJECT

public:
	virtual void Execute() = 0;
	virtual std::shared_ptr<ICommand> Clone() const = 0;
	
	virtual bool MainOptionRequired() const = 0;
	virtual size_t RequiredMinOptionsCount() const = 0;

	virtual bool Acceptarg(std::string const&, std::any) = 0;
	virtual bool Validate() const = 0;

	virtual bool AcceptMainOption(std::string const&);

signals:
	void CreatedAction(IAction_SPtr&);

protected:
	ICommand() = default;
	ICommand(ICommand const&);

protected:
	std::vector<std::string> accept_options;

	std::string main_option{};
	std::map<std::string, std::any> values;
};

} 

using ICommandPtr = std::shared_ptr<class Command::ICommand>;
using ICommandsList = std::queue<ICommand_SPtr>;

} 

#endif // INTERFACE_ICOMMAND_HPP_