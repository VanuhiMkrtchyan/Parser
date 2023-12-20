
#include "draw.hpp"

namespace pwpt
{

Painter::Painter(std::ostream* pOstream)
	: output{ pOstream }
{}

void Painter::Draw(Shape const& oShape, double x1, double y1, double x2, double y2, QColor oColor)
{
	*output << oShape.ToString();
	PrintGeometry(x1, y1, x2, y2);
	*output << oColor.name().toStdString();
}

void Painter::Draw(Shape const& oShape, QPointF const& p1, QPointF const& p2, QColor oColor)
{
	Draw(oShape, p1.x(), p1.y(), p2.x(), p2.y(), oColor);
}

void Painter::DrawRect(double x1, double y1, double x2, double y2, QColor oColor)
{
	Draw(Shape{ Shape::EShape::Rectangle }, x1, y1, x2, y2, oColor);
}

void Painter::DrawRect(QPointF const& p1, QPointF const& p2, QColor oColor)
{
	Draw(Shape{ Shape::EShape::Rectangle }, p1.x(), p1.y(), p2.x(), p2.y(), oColor);
}

void Painter::DrawText(double x1, double y1, double x2, double y2, QString const& sText, QColor oColor)
{
	Draw(Shape{ Shape::EShape::TextBox }, x1, y1, x2, y2, oColor);
}

void Painter::DrawText(QPointF const& p1, QPointF const& p2, QString const& sText, QColor oColor)
{
	Draw(Shape{ Shape::EShape::TextBox }, p1.x(), p1.y(), p2.x(), p2.y(), oColor);
}

void Painter::PrintGeometry(double x1, double y1, double x2, double y2)
{
	*output << " (" << x1 << "," << y1 << ")" << " " << "(" << x2 << "," << y2 << ") ";
}

} // namespace pwpt