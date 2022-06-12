#include "home.h"
#include "ui_home.h"
#include"login.h"
#define home_png "D:/QT project/libManager/image/aaa.png"
home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    setWindowTitle("Staff home");

    QPixmap pix(home_png);
    ui->image->setPixmap(pix);
}

home::~home()
{
    delete ui;
}



void home::on_btnExitStaff_clicked()
{
    connect(ui->btnExitStaff,SIGNAL(clicked()),this,SLOT(close()));

}

void home::on_managerStaff_clicked()
{
        Wmanstaff.show();
}

void home::on_managerMem_clicked()
{

    Wmanmember.show();
}

void home::on_managerBook_clicked()
{
    Wmanbook.show();
}

void home::on_btnAbout_clicked()
{
    QMessageBox :: warning(this,"about","Design by Nguyen Huan") ;
}





void home::on_btninfo_clicked()
{
    Winfostaff.show();
}

void home::on_btnbookdata_clicked()
{
    Wbookdata.show();
}
