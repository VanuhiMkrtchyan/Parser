
#ifndef DRAW_HPP
#define DRAW_HPP

#include <exception>

#include <QColor>
#include <QPainter>
#include <QPointF>

#include "shape.hpp"

namespace pwpt
{

class IDraw
{
public:
	virtual void Draw(Shape const&, double x1, double y1, double x2, double y2, QColor = Qt::blue) = 0;
	virtual void Draw(Shape const&, QPointF const& p1, QPointF const& p2, QColor = Qt::blue) = 0;

	virtual void DrawRect(double x1, double y1, double x2, double y2, QColor = Qt::blue) = 0;
	virtual void DrawRect(QPointF const& p1, QPointF const& p2, QColor = Qt::blue) = 0;

	virtual void DrawText(double x1, double y1, double x2, double y2, QString const& sText, QColor = Qt::blue) = 0;
	virtual void DrawText(QPointF const& p1, QPointF const& p2, QString const& sText, QColor = Qt::blue) = 0;
};

} // namespace pwpt

#endif // DRAW_HPP
