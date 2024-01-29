#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>
class Validator
{
public:
    //Validator()         {};
    virtual ~Validator() {};
    virtual bool isValid(QString somestring)=0;
};
class SomeValidator : public Validator
{
public:
    virtual bool isValid(QString somestring)
    {
        return true;
    }
};
class NewValidator : public Validator
{
    QRegularExpression reg;
public:
    NewValidator(QString str)
    {
        reg = QRegularExpression (str);
    }
    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch = reg.match(somestring);
        bool ismatch = regmatch.hasMatch();
        if  (ismatch==true)
            return true;
        else
            return false;
    }
};
class EmailValidator: public Validator{
    QString str = "^[a-zA-Z0-9.!#$%&'*+-/=? ^_`{|}~]+@gmail\\.com$";
    QRegularExpression reg=QRegularExpression(str);
public:

    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch = reg.match(somestring);
        bool ismatch = regmatch.hasMatch();
        return ismatch;
    }
};









QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
