#include "serialize.hpp"

void Serialazer::save(Document& doc, const std::string file){
    std::ofstream file_doc("../Saved/" + file);
    for(auto& slide : doc.get_slides()){
        file_doc << slide << "\n";
        for(const auto& [id,item] : slide){
            file_doc << "-name "<< item->info() << "\n";
        }
    }
    
}
void load(Document& doc, const std::string file){
    std::ifstream file_doc("../Saved/" + file);
    std::string line;

    ///TODO: implemen
}