/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *studentBox;
    QComboBox *seminarBox;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *markBox;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *saveButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nameEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveallButton;
    QPushButton *closeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(661, 431);
        MainWindow->setIconSize(QSize(20, 30));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        studentBox = new QComboBox(centralWidget);
        studentBox->addItem(QString());
        studentBox->addItem(QString());
        studentBox->setObjectName(QString::fromUtf8("studentBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(studentBox->sizePolicy().hasHeightForWidth());
        studentBox->setSizePolicy(sizePolicy);
        studentBox->setIconSize(QSize(20, 16));

        horizontalLayout->addWidget(studentBox);

        seminarBox = new QComboBox(centralWidget);
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->addItem(QString());
        seminarBox->setObjectName(QString::fromUtf8("seminarBox"));
        sizePolicy.setHeightForWidth(seminarBox->sizePolicy().hasHeightForWidth());
        seminarBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(seminarBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        markBox = new QComboBox(centralWidget);
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->addItem(QString());
        markBox->setObjectName(QString::fromUtf8("markBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(markBox->sizePolicy().hasHeightForWidth());
        markBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(markBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        saveButton = new QToolButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout_2->addWidget(nameEdit);

        horizontalSpacer = new QSpacerItem(200, 5, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setIconSize(QSize(20, 5));

        horizontalLayout_2->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        saveallButton = new QPushButton(centralWidget);
        saveallButton->setObjectName(QString::fromUtf8("saveallButton"));

        horizontalLayout_3->addWidget(saveallButton);

        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_3->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 661, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(closeButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\276\321\206\320\265\320\275\320\272\321\203 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\321\203:", nullptr));
        studentBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        studentBox->setItemText(1, QCoreApplication::translate("MainWindow", "--", nullptr));

        seminarBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\265\320\274\320\270\320\275\320\260\321\200", nullptr));
        seminarBox->setItemText(1, QCoreApplication::translate("MainWindow", "--", nullptr));
        seminarBox->setItemText(2, QCoreApplication::translate("MainWindow", "1", nullptr));
        seminarBox->setItemText(3, QCoreApplication::translate("MainWindow", "2", nullptr));
        seminarBox->setItemText(4, QCoreApplication::translate("MainWindow", "3", nullptr));
        seminarBox->setItemText(5, QCoreApplication::translate("MainWindow", "4", nullptr));
        seminarBox->setItemText(6, QCoreApplication::translate("MainWindow", "5", nullptr));
        seminarBox->setItemText(7, QCoreApplication::translate("MainWindow", "6", nullptr));
        seminarBox->setItemText(8, QCoreApplication::translate("MainWindow", "7", nullptr));
        seminarBox->setItemText(9, QCoreApplication::translate("MainWindow", "8", nullptr));

        markBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        markBox->setItemText(1, QCoreApplication::translate("MainWindow", "--", nullptr));
        markBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\235", nullptr));
        markBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\237", nullptr));
        markBox->setItemText(4, QCoreApplication::translate("MainWindow", "\320\240", nullptr));

        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260 \320\262 \320\261\320\260\320\267\321\203:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        saveallButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
