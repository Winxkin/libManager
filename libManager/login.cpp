#include "login.h"
#include "ui_login.h"
#include"global_variable.h"
#define login_png "D:/QT project/libManager/image/library.png"
QString gUsername;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    QPixmap pix(login_png);
    ui->imagelogin->setPixmap(pix);

}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_login_clicked()
{   staff staff_conn ;
    staff_conn.connect();
    QString username,password;
    username = ui->txtusername->text();
    password = ui->txtpassword->text();

    gUsername = username ;  //get username when login
 //   qDebug() << gUsername << endl;
    if (username == NULL || password == NULL) {
         QMessageBox :: warning(this,"error","please enter your username and password") ;
    }

    else if (ui->radioStaff->isChecked()) {
                QSqlQuery Squery;
                QString Sprepare = "SELECT username, password From Staff WHERE username= :username and password= :password  "   ;
                Squery.prepare(Sprepare);
                Squery.bindValue(":username", username);
                Squery.bindValue(":password", password);

                if (Squery.exec()) {
                    int c1=0;
                    while (Squery.next()) c1 ++;
                    if (c1 == 1)   {
                        this->hide();
                        WStaffhome.show();
                    }
                    else QMessageBox :: warning(this,"error","username or password is not correct") ;
                }
    }

    else if (ui->radioMember->isChecked()) {
                QSqlQuery Mquery;
                QString Mprepare = "SELECT username, password From Member WHERE username= :username and password= :password  "   ;
                Mquery.prepare(Mprepare);
                Mquery.bindValue(":username", username);
                Mquery.bindValue(":password", password);
                if (Mquery.exec()) {
                    int c2=0;
                    while (Mquery.next()) c2 ++;
                    if (c2 == 1)   {
                        this->hide();
                        WMemhome.show();
                    }
                    else QMessageBox :: warning(this,"error","username or password is not correct") ;
                }
    }

    else {
        QMessageBox :: warning(this,"error","please choose login with staff or member") ;
    }
staff_conn.Disconnect();

 }


void Login::on_btn_exit_clicked()
{
    connect (ui->btn_exit,SIGNAL(clicked()),this,SLOT(close()));
}

 QString Login::getusername(){
     return ui->txtusername->text();
 }

bool Login::getradiomember(){
    return ui->radioMember->isChecked();
}

bool Login::getradiostaff(){
    return ui->radioStaff->isChecked();
}
