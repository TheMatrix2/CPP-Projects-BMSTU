/********************************************************************************
** Form generated from reading UI file 'attendance.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCE_H
#define UI_ATTENDANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Attendance
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Attendance)
    {
        if (Attendance->objectName().isEmpty())
            Attendance->setObjectName(QString::fromUtf8("Attendance"));
        Attendance->resize(800, 600);
        centralwidget = new QWidget(Attendance);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Attendance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Attendance);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Attendance->setMenuBar(menubar);
        statusbar = new QStatusBar(Attendance);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Attendance->setStatusBar(statusbar);

        retranslateUi(Attendance);

        QMetaObject::connectSlotsByName(Attendance);
    } // setupUi

    void retranslateUi(QMainWindow *Attendance)
    {
        Attendance->setWindowTitle(QApplication::translate("Attendance", "Attendance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Attendance: public Ui_Attendance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCE_H
