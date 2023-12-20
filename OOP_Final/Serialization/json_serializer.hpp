#ifndef JSON_SERIALIZER_HPP
#define JSON_SERIALIZER_HPP

#include "../Doc/i_document.hpp"
#include "../Doc/i_slide.hpp"

#include <memory>

class J_Serializer
{

public:
    std::string serializeToJson(const std::shared_ptr<Document>& document);

private:
    std::string serializeSlide(const std::shared_ptr<Slide>& slide);

    std::string serializeItem(const std::shared_ptr<Item> item);
};

#endif //  JSON_SERIALIZER_HPP
