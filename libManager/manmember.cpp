#include "manmember.h"
#include "ui_manmember.h"

manmember::manmember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manmember)
{
    ui->setupUi(this);
    setWindowTitle("Manage member");
//--------------------------Load table---------------------------------------
    staff Mconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    Mconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Mconn.getdata());
    QString view = "SELECT * FROM Member" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Mconn.Disconnect();
}

manmember::~manmember()
{
    delete ui;
}



void manmember::on_btnadd_clicked()
{
           staff Mconn ;
           int flat=0;
            QString username = ui->txtusername->text();
            QString password = ui->txtpassword->text();
            QString name = ui->txtname->text();
            QString age = ui->txtage->text();

    //-----------------------------------------------------------------------------------------------inspect Staff account
            if ( username == NULL || password==NULL || name==NULL || age==NULL) {
                QMessageBox :: warning(this,"error","Please fill out the form") ;
                flat=1;
            }
            else {
                    QSqlQuery qry;
                    Mconn.connect();
                    QString Mprepare1 = "SELECT username From Member WHERE username= :username   "   ;
                    qry.prepare(Mprepare1);
                    qry.bindValue(":username", username);

                    if (qry.exec()) {
                        int c=0;
                        while (qry.next()) c ++;
                        if (c == 1)   {
                            QMessageBox :: warning(this,"error","Username already exists, please choose another name") ;

                            flat=1;
                        }

                    }

            }
    //-------------------------------------------------Add new staff account
         if (flat==1) Mconn.Disconnect();
         else {

            QSqlQuery query;
            Mconn.connect();
            QString Mprepare2 = "INSERT INTO Member (username,password,name,age) VALUES ('"+username+"','"+password+"','"+name+"','"+age+"') ";
            query.prepare(Mprepare2);



            if (query.exec()) {
                   QMessageBox :: warning(this,"successful","New member have been added") ;
                   //add username to table borrowbook.

                   Mconn.Disconnect();
               }
               else {
                   QMessageBox :: warning(this,"error","Can not addition!") ;
                   Mconn.Disconnect();
               }
          }
//-----------------------Load table----------------------------------------------
         QSqlQueryModel *model= new QSqlQueryModel ();
         Mconn.connect();
         QSqlQuery *queryload = new QSqlQuery(Mconn.getdata());
         QString view = "SELECT * FROM Member" ;
         queryload->prepare(view);
         queryload->exec();
         model->setQuery(*queryload);
         ui->tableView->setModel(model);
         Mconn.Disconnect();


}

void manmember::on_btnupdate_clicked()
{
    staff Mconn;
    QString updateusername = ui->txtupdateusername->text();

    QString password = ui->txtnewpassword->text();
    QString name = ui->txtnewname->text();
    QString age = ui->txtnewage->text();
    if (updateusername == NULL  || password==NULL || name ==NULL || age== NULL) {

        QMessageBox :: warning(this,"error","please fill out the form to update") ;
    }
    else {
        Mconn.connect();
        QSqlQuery query;
        QString update = " UPDATE Member SET  password='"+password+"', name='"+name+"',age='"+age+"' WHERE username='"+updateusername+"'  ";

        query.prepare(update) ;
        if(query.exec()) {
             //update username for Borrowbook table.
          //  QMessageBox :: warning(this,"successful","update successful !") ;
        }



        Mconn.Disconnect();
    }
    //--------------------Load table--------------------------------------------
    QSqlQueryModel *model= new QSqlQueryModel ();
    Mconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Mconn.getdata());
    QString view = "SELECT * FROM Member" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Mconn.Disconnect();

}

void manmember::on_btndelete_clicked()
{
    staff Mconn;
    QString username = ui->txtdelusername->text();

    if (username==NULL) {
        QMessageBox :: warning(this,"error","please enter username to delete") ;
    }
    else {
        Mconn.connect();
        QSqlQuery query ;
        QString del = " DELETE FROM Member WHERE username='"+username+"'   ";
        query.prepare(del) ;
       if( query.exec()) {

       // QMessageBox :: warning(this,"successful","delete successful !") ;
            //delete colums username of Borrowbook

       }
            Mconn.Disconnect();
    }
    //--------------------Load table--------------------------------------------
    QSqlQueryModel *model= new QSqlQueryModel ();
    Mconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Mconn.getdata());
    QString view = "SELECT * FROM Member" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Mconn.Disconnect();
}
