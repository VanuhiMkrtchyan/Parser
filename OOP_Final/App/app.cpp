#include "app.hpp"

namespace pwpt
{

namespace app
{

PwPtDoc_SPtr App::get_document() const
{
	return document;
}

std::ostream* App::GetOutputStreamDevice() const
{
	return OutputStream;
}

} // namespace app

} // namespace pwpt