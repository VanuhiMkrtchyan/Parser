#ifndef POWER_POINT_HPP
#define POWER_POINT_HPP

#include <QtWidgets/QMainWindow>
#include "ui_powerpoint.h"

#include "../Doc/document.hpp"
#include "../Factory/command_handler.hpp"

QT_BEGIN_NAMESPACE
namespace ui { class PowerPointClass; };
QT_END_NAMESPACE

namespace pwpt
{

namespace app
{

class PowerPoint : public QMainWindow
{
    Q_OBJECT

public:
    PowerPoint(QWidget *parent = nullptr);
    ~PowerPoint();

private:
    ui::PowerPointClass *ui;
};

} // namespace app

} // namespace pwpt

#endif //POWER_POINT_HPP
