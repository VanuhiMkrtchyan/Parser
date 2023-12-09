#include "object.hpp"

namespace pwpt
{

QPointF Object::get_center() const
{
	return center_;
}

QColor Object::get_color() const 
{
	return color_;
}

QPair<QPointF, QPointF> Object::get_geometry() const 
{
	return QPair<QPointF, QPointF>{lt_pos_, rb_pos_};
}

Shape Object::get_shape() const
{
	return shape_;
}


void Object::get_center(QPointF const& oCenter) 
{
	double PartLenOnX = center_.x() - lt_pos_.x();
	double PartLenOnY = center_.y() - lt_pos_.y();

	center_ = oCenter;

	lt_pos_.setX(center_.x() - PartLenOnX);
	lt_pos_.setY(center_.y() + PartLenOnY);

	rb_pos_.setX(center_.x() + PartLenOnX);
	rb_pos_.setY(center_.y() - PartLenOnY);
}

void Object::SetGeometry(QPointF const& oLeftTop, QPointF const& oRightBottom) 
{
	lt_pos_ = oLeftTop;
	rb_pos_ = oRightBottom;

	center_.setX((lt_pos_.x() + rb_pos_.x()) / 2);
	center_.setY((lt_pos_.y() + rb_pos_.y()) / 2);
}

void Object::set_shape(Shape const& eShape)
{
	shape_ = eShape;
}

void Object::set_color(QColor const& oColor) 
{
	color_ = oColor;
}

} // namespace pwpt