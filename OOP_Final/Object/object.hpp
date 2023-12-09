#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <deque>
#include <memory>

#include <QColor>
#include <QPair>
#include <QPointF>

#include "shape.hpp"

namespace pwpt
{

class Object
{
public:
	QPointF get_center() const override;
	QPair<QPointF, QPointF> get_geometry() const override;
	Shape get_shape() const override;
	QColor get_color() const override;

	void set_center(QPointF const&) override;
	void set_center(QPointF const&, QPointF const&) override;
	void set_shape(Shape const&) override;
	void set_color(QColor const&) override;

private:
	QPointF center_;
	Shape shape_;
	QColor color_;

	QPointF lt_pos_;
	QPointF rb_pos_;
};

} 

#endif // OBJECT_HPP_