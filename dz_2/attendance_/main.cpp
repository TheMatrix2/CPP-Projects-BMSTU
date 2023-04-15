#include "attendance.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Attendance w;
    w.show();
    return a.exec();
}
