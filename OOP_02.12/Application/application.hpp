#ifndef APP_HPP
#define APP_HPP

#include "../IO/io_stream.hpp"
#include "../Controller/controller.hpp"

class Application{
    public:
        Application() : doc_{std::move(std::make_shared<Document>())}, io_{std::move(std::make_shared<IO_Stream>())}, {doc_}, is_running{true}{}
        void execute();
    private:
        bool is_running;
        Document doc_;
        Controller controller_;
        IO_Stream io_;
};

#endif //APP_HPP