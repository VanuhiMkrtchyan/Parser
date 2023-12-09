#include "document.hpp"
#include "slide.hpp"

namespace pwpt
{

namespace Document
{

Document::Document()
	: slide_show{ nullptr }
	, slide_index{ 0 }
	, shape_{ Shape::Enum_Shape::None }
	, color_{ Qt::black }
{
	slide_show = std::make_shared<Slide>();
}

ISlideContainer_SPtr Document::GetSlideShow()
{
	return slide_show;
}

int Document::GetActiveSlideIndex() const
{
	return slide_index;
}

void Document::SetActiveSlide(size_t const iIndex)
{
	slide_index = iIndex;
}

CShape Document::GetShape()
{
	return shape_;
}

void Document::SetShape(CShape const& eShape)
{
	shape_ = eShape;
}

QColor Document::GetColor() const
{
	return color_;
}

void Document::SetColor(QColor const oColor)
{
	color_ = oColor;
}

} // namespace Document

} // namespace pwpt