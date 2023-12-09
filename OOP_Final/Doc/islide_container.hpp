#ifndef INTERFACE_ISLIDECONTAINER_HPP
#define INTERFACE_ISLIDECONTAINER_HPP

#include <memory>

#include "i_slide.hpp"

namespace pwpt
{

class ISlideContainer
{
public:
    using size_type = size_t;

    virtual bool IsEmpty() const = 0;
    virtual size_type Count() const = 0;

    virtual void Clear() = 0;

    virtual void Remove(int nSlideIndex, size_type nCount = 1) = 0;

    virtual void Add(SlidePtr) = 0;

    virtual void Insert(SlidePtr, int nIndex) = 0;

    virtual SlidePtr GetSlide(int nIndex) const = 0;

}; 
using SlideContainerPtr = std::shared_ptr<class ISlideContainer>;
} // namespace pwpt

#endif // INTERFACE_ISLIDECONTAINER_HPP