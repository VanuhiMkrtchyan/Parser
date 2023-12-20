
#ifndef PAINTER_HPP
#define PAINTER_HPP
#include <iostream>
#include <memory>

#include "i_draw.hpp"

namespace pwpt
{

class Painter : public IDraw
{
public:
	Painter(std::ostream* = &std::cout);

	void Draw(Shape const&, double x1, double y1, double x2, double y2, QColor = Qt::blue) override;
	void Draw(Shape const&, QPointF const& p1, QPointF const& p2, QColor = Qt::blue) override;

	void DrawRect(double x1, double y1, double x2, double y2, QColor = Qt::blue) override;
	void DrawRect(QPointF const& p1, QPointF const& p2, QColor = Qt::blue) override;

	void DrawText(double x1, double y1, double x2, double y2, QString const& sText, QColor = Qt::blue) override;
	void DrawText(QPointF const& p1, QPointF const& p2, QString const& sText, QColor = Qt::blue) override;
private:
	void PrintGeometry(double x1, double y1, double x2, double y2);

private:
	std::ostream* output = nullptr;
};

} // namespace pwpt

#endif // PAINTER_HPP
