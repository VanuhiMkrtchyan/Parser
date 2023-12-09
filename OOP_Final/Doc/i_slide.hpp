#ifndef INTERFACE_SLIDE_HPP
#define INTERFACE_SLIDE_HPP

#include "../Object/object.hpp"

namespace pwpt
{

class ISlide
{
public:
    using size_type     = size_t;
    virtual bool IsEmpty() const = 0;
    virtual size_type GetCount() const = 0;
    virtual void Clear() = 0;
    virtual void Clear(QPointF const& pLeftTop, QPointF const& pRightBottom) = 0;
    virtual void Remove(QPointF const& pObjectsCenter) = 0;
    virtual void Add(IObject_SPtr oObject) = 0;
    virtual IObject_SPtr GetObject(QPointF const&) const = 0;
    virtual ObjectList GetObjects(QPointF pLeftTop, QPointF pRightBottom) const = 0;
    virtual ObjectList GetObjects() const = 0;

}; using SlidePtr = std::shared_ptr<class ISlide>;

} 

#endif // INTERFACE_SLIDE_HPP