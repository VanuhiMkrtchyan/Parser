#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "islide_conatiner.hpp"
#include "i_document.hpp"

namespace pwpt
{

namespace Document
{

class Document : public IDocument
{
public:
	Document();
	Document(Document const&) = delete;
	Document& operator=(Document const&) = delete;

	ISlideContainer_SPtr GetSlideShow() override;
	int GetActiveSlideIndex() const override;
	void SetActiveSlide(size_t const iIndex) override;
	
	CShape GetShape() override;
	void SetShape(CShape const&) override;
	
	QColor GetColor() const override;
	void SetColor(QColor const) override;

private:
	int slide_index;
	Shape shape_;
	QColor color_;
	pwpt::SlideContainerPtr slide_show;

}; 

} 

} 


#endif // DOCUMENT_HPP