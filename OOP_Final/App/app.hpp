#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <memory>

#include "../Doc/i_document.hpp"
#include "../IO/io_interface.hpp"

namespace pwpt
{

namespace app
{

class App
{
	public:
		App(App const&) = delete;
		App& operator=(App const&) = delete;

		virtual void Run() = 0;
		
		PwPtDoc_SPtr get_document() const;
		std::ostream* GetOutputStreamDevice() const;

	protected:
		App() =default;

	protected:
		PwPtDoc_SPtr document = nullptr;
	std::ostream* OutputStream = &std::cout;
};

} // namespace app

} // namespace pwpt

#endif //APP_HPP