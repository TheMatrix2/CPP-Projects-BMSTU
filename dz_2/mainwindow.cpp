#include "mainwindow.h"
#include "ui_mainwindow.h"

// вспомогательная функция для разделения строки по заданному символу
vector<string> split(const string& s, char separator){
    vector<string> output;
    string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(separator, pos)) != string::npos)
    {
        string substring( s.substr(prev_pos, pos-prev_pos) );
        output.push_back(substring);
        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

    return output;
}

// чтение файла с базой
vector<Student> read_file(){
    const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
    locale::global(utf8_locale);

    ifstream file("F:/untitled/database.csv");
    file.imbue(utf8_locale);
    string line;
    vector<Student> students;
    int s = 1;
    while (getline(file, line)){
        if (line == "\000")
            continue;

        if (s == 1){
            s += 1;
            continue;
        }

        else{
            vector<string> vec = split(line, ';');
            vector<string> marks;
            for (int i = 1; i < vec.size(); i++)
                marks.push_back(vec[i]);
            Student student = {vec[0], marks};
            students.push_back(student);
        }
    }

    file.close();

    return students;
}

// перезапись файла
void write_file(vector<Student> vec){
    const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
    locale::global(utf8_locale);

    ofstream file;
    file.imbue(utf8_locale);
    file.open("F:/untitled/database.csv");
    file << ";1;2;3;4;5;6;7;8" << endl;
    for (Student i : vec){
        file << i.get_name();
        for (int j = 0; j < i.get_marks().size(); j++)
            file << ";" << i.get_marks()[j];
        file << endl;
    }

    file.close();
}


// конструктор
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // reading file to comboBox
    vector<Student> students = read_file();
    for (int i = 0; i < students.size(); i++){
        QString st = QString::fromStdString(students[i].get_name());
        ui->studentBox->addItem(st);
    }
}

// деструктор
MainWindow::~MainWindow()
{
    delete ui;
}

// нажатие кнопки "добавить"
void MainWindow::on_addButton_clicked()
{

    QString name = ui->nameEdit->text();
    if (name == "")
        return;
    ui->studentBox->addItem(name);
    ui->nameEdit->clear();

    vector<Student> students = read_file();
    Student new_student = {name.toStdString(), {"","","","","","","",""}};
    students.push_back(new_student);

    write_file(students);
}

// нажатие кнопки "сохранить"
void MainWindow::on_saveButton_clicked()
{
    if (ui->studentBox->currentIndex() == 0 || ui->studentBox->currentIndex() == 1 || ui->markBox->currentIndex() == 0 || ui->markBox->currentIndex() == 1 || ui->seminarBox->currentIndex() == 0 || ui->seminarBox->currentIndex() == 1)
        QMessageBox::critical(this, "Ошибка", "Заполните все поля");
    string name = ui->studentBox->currentText().toStdString();
    string mark = ui->markBox->currentText().toStdString();

    vector<Student> students = read_file();
    int k;
    for (int i = 0; i < students.size(); i++)
        if (students[i].get_name() == name)
            k = i;

    vector<string> temp = students[k].get_marks();
    temp[ui->seminarBox->currentIndex() - 2] = mark;
    students[k].set_marks(temp);

    write_file(students);
}

void MainWindow::on_saveallButton_clicked()
{
    QMessageBox::information(this, "Сохранено", "Внесенные изменения сохранены");
}
