#include "power_point.hpp"
#include "../Command/i_command.hpp"

namespace pwpt
{ 

namespace app
{ 

PowerPoint::PowerPoint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new ui::PowerPointClass())
{
    ui->setupUi(this);
}

PowerPoint::~PowerPoint()
{
    delete ui;
}

} // namespace app

} // namespace pwpt