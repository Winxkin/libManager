#include "infomember.h"
#include "ui_infomember.h"
#include"global_variable.h"

infomember::infomember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infomember)
{
    ui->setupUi(this);
}

infomember::~infomember()
{
    delete ui;
}

void infomember::on_btnviewinfo_clicked()
{
    staff data;
    data.connect();
    QSqlQuery query;
    QString view = " SELECT * FROM Member WHERE username = '"+gUsername+"' ";
    query.prepare(view);
    query.exec();
    while(query.next()) {
        ui->labelusername->setText(query.value(0).toString());  //tại cột thứ 0
        ui->labelname->setText(query.value(2).toString());          //tại cột thứ 2
        ui->labelage->setText(query.value(3).toString());               //tại cột thứ 3
    }
    data.Disconnect();
}

void infomember::on_btnchange_clicked()
{
    staff data;
    QString newpassword=ui->txtnewpassword->text();
    if(newpassword==NULL) QMessageBox :: warning(this,"error","please enter new password") ;

    else{
                data.connect();
                QSqlQuery query;
                QString update = "UPDATE Member SET password='"+newpassword+"' WHERE username='"+gUsername+"'  ";
                query.prepare(update);
                if (query.exec())   QMessageBox :: warning(this,"successful","Password had change") ;
                data.Disconnect();

           }
}
