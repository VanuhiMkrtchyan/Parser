#ifndef APP_MANAGER_HPP
#define APP_MANAGER_HPP

#include "app.hpp"

namespace pwpt
{

namespace app
{

class App_Manager
{
public:
	App_Manager(App_Manager const&) = delete;
	App_Manager& operator=(App_Manager const&) = delete;

	static App& AppInstance();

private:
	App_Manager();
};

} 

} 


#endif // APP_MANAGER_HPP