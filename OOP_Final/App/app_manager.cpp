#include "application.hpp"
#include "app_manager.hpp"

namespace pwpt
{

namespace app
{

App& App_Manager::AppInstance()
{
	static Power_Point_App app;
	return app;
}

App_Manager::App_Manager()
{}

}

} 