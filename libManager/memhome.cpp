#include "memhome.h"
#include "ui_memhome.h"
#define memhome_png "D:/QT project/libManager/image/aaa.png" //link to change image
MemHome::MemHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemHome)
{
    ui->setupUi(this);
    setWindowTitle("Member home");

    QPixmap pix(memhome_png);
    ui->image->setPixmap(pix);
}

MemHome::~MemHome()
{
    delete ui;
}



void MemHome::on_btnExitmem_clicked()
{
    connect(ui->btnExitmem,SIGNAL(clicked()),this,SLOT(close()));
}



void MemHome::on_btnfindbook_clicked()
{
    Wfindbook.show();
}

void MemHome::on_btnabout_clicked()
{
    QMessageBox :: warning(this,"about","Design by Nguyen Huan") ;
}

void MemHome::on_btninfo_clicked()
{
    Winfomember.show();
}

void MemHome::on_btnbrrowbook_clicked()
{
    Wborrow.show();
}

void MemHome::on_btnreturnbook_clicked()
{
    Wbreturn.show();
}
