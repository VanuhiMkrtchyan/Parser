#ifndef INTERFACE_DOCUMENT_HPP
#define INTERFACE_DOCUMENT_HPP

#include <memory>

#include <QColor>

#include "islide_container.hpp"
#include "shape.hpp"

namespace pwpt
{

namespace Document
{

class IDocument
{
public:
	virtual ISlideContainer_SPtr GetSlideShow() = 0;
	virtual int GetActiveSlideIndex() const = 0;
	virtual void SetActiveSlide(size_t const iIndex) = 0;
	
	virtual Shape GetShape() = 0;
	virtual void SetShape(CShape const&) = 0;

	virtual ELineThickness GetLineThickness() const = 0;
	virtual void SetLineThickness(ELineThickness const) = 0;

	virtual QColor GetColor() const = 0;
	virtual void SetColor(QColor const) = 0;

};

} 
using DocPtr = std::shared_ptr<class Document::IDocument>;

} 

#endif // INTERFACE_DOCUMENT_HPP_