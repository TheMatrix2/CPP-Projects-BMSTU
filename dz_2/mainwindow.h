#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "student.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend vector<Student> read_file();
    friend void write_file(vector<Student> vec);
    friend vector<string> split(const std::string& s, char separator);

private slots:
    void on_addButton_clicked();

    void on_saveButton_clicked();

    void on_saveallButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
