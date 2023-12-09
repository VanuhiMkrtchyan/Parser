#include "../Power_Point/power_point.hpp"
#include "../App/app_manager.hpp"

#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    using namespace pwpt::App;

    QCoreApplication a(argc, argv);
    
    auto& app = App_Manager::AppInstance();
    app.Run();

    return a.exec();
}