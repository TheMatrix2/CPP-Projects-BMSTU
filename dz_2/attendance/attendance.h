#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Attendance; }
QT_END_NAMESPACE

class Attendance : public QWidget
{
    Q_OBJECT

public:
    Attendance(QWidget *parent = nullptr);
    ~Attendance();

private:
    Ui::Attendance *ui;
};
#endif // ATTENDANCE_H
