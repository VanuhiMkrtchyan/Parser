#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "app.hpp"
#include "../Factory/command_handler.hpp"
#include "../Edit/i_edit.hpp"

namespace pwpt
{

namespace app
{

class Power_Point_App : public App
{ 
public:
	Power_Point_App();
	Power_Point_App(Power_Point_App const&) = delete;
	Power_Point_App& operator=(Power_Point_App const&) = delete;

	void Run() override;

private:
	ICommandLine_UPtr		m_pConsole = nullptr;
	ICommandHandler_UPtr	m_pCommandHandler = nullptr;
	IMachine_UPtr			m_pActionMachine;

}; // class Power_Point_App

} // namespace app

} // namespace pwpt

#endif // APPLICATION_HPP