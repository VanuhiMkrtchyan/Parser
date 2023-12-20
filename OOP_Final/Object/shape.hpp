#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

namespace pwpt
{

class Shape
{
public:
	enum class Enum_Shape
	{
		None,
		Rectangle,
		Triangle,
		Circular,
		Text
	};

	explicit Shape(Enum_Shape);
	Shape(std::string const&);

	std::string to_string() const;

	Enum_Shape get_shape() const;

	void set_shape(Enum_Shape);
	void set_shape(std::string const&);

private:
	Enum_Shape e_shape;
	std::string str_shape;
};

} // namespace pwpt

#endif // SHAPE_HPP_