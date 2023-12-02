#include "IO/io_stream.hpp"
#include "Application/application.hpp"

int main(int argc, char* argv[]){
    std::cout << "Starting main" << std::endl;
    IO_Stream io;
    Application app(io);
    app.execute();
}
