#include "shape.hpp"

namespace pwpt
{

Shape::Shape(Shape::Enum_Shape eShape)
	: e_shape{ Enum_Shape::None }
	, str_shape{ "None" }
{
	set_shape(eShape);
}

Shape::Shape(std::string const& sShape)
	: e_shape{ Enum_Shape::None }
	, str_shape{ "None" }
{
	set_shape(sShape);
}

std::string Shape::to_string() const
{
	return str_shape;
}

Shape::Enum_Shape Shape::get_shape() const
{
	return e_shape;
}

void Shape::set_shape(Enum_Shape eShape)
{
	e_shape = eShape;

	switch (e_shape)
	{
	case Enum_Shape::Rectangle:
		str_shape = "Rectangle";
		break;
	case Enum_Shape::Triangle:
		str_shape = "Triangle";
		break;
	case Enum_Shape::Circular:
		str_shape = "Circle";
		break;
	default:
		str_shape = "None";
		break;
	}
}

void Shape::set_shape(std::string const& sShape)
{
	str_shape = sShape;

	if (sShape == "Rectangle")
		e_shape = Enum_Shape::Rectangle;
	else if (sShape == "Triangle")
		e_shape = Enum_Shape::Triangle;
	else if (sShape == "Circle")
		e_shape = Enum_Shape::Circular;
	else
		e_shape = Enum_Shape::None;
}

} // namespace pwpt