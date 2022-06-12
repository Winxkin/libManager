#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <qdebug.h>
#include<QString>
#include<QMessageBox>
#include"staff.h"
#include"home.h"
#include"memhome.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btn_login_clicked();

    void on_btn_exit_clicked();
    QString getusername();

    bool getradiomember();
    bool getradiostaff();


private:
    Ui::Login *ui;
    home WStaffhome;
    MemHome WMemhome;
};



#endif // LOGIN_H
