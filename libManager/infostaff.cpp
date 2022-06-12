#include "infostaff.h"
#include "ui_infostaff.h"
#include"global_variable.h"


infostaff::infostaff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infostaff)
{
    ui->setupUi(this);
    setWindowTitle("Information");

}

infostaff::~infostaff()
{
    delete ui;
}


void infostaff::on_btnchange_clicked()
{
    staff data;
    QString newpassword=ui->txtnewpassword->text();
    if(newpassword==NULL) QMessageBox :: warning(this,"error","please enter new password") ;

    else {
                data.connect();
                QSqlQuery query;
                QString update = "UPDATE Staff SET password='"+newpassword+"' WHERE username='"+gUsername+"'  ";
                query.prepare(update);
                if (query.exec())   QMessageBox :: warning(this,"successful","Password had change") ;
                data.Disconnect();
           }

}

void infostaff::on_btnviewinfo_clicked()
{
    staff data;
    data.connect();
    QSqlQuery query;
    QString view = " SELECT * FROM Staff WHERE username = '"+gUsername+"' ";
    query.prepare(view);
    query.exec();
    while(query.next()) {
        ui->lableusername->setText(query.value(0).toString());
        ui->lablename->setText(query.value(2).toString());
        ui->lableage->setText(query.value(3).toString());
    }
    data.Disconnect();
}
