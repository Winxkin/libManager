#include "manstaff.h"
#include "ui_manstaff.h"

ManStaff::ManStaff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManStaff)
{
    ui->setupUi(this);
    setWindowTitle("Manage staff");
//-----------------------------------------------------------

    staff Sconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    Sconn.connect();
    QSqlQuery *query = new QSqlQuery(Sconn.getdata());
    QString view = "SELECT * FROM Staff" ;
    query->prepare(view);
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    Sconn.Disconnect();

}

ManStaff::~ManStaff()
{
    delete ui;
}



void ManStaff::on_btnADD_clicked()
{      staff Sconn ;
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
                Sconn.connect();
                QString Sprepare1 = "SELECT username From Staff WHERE username= :username   "   ;
                qry.prepare(Sprepare1);
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
     if (flat==1) Sconn.Disconnect();
     else {

        QSqlQuery query;
        Sconn.connect();
        QString Sprepare2 = "INSERT INTO Staff (username,password,name,age) VALUES ('"+username+"','"+password+"','"+name+"','"+age+"') ";
        query.prepare(Sprepare2);



        if (query.exec()) {
               QMessageBox :: warning(this,"successful","New employee have been added") ;
               Sconn.Disconnect();
           }
           else {
               QMessageBox :: warning(this,"error","Can not addition!") ;
               Sconn.Disconnect();
           }
      }
//----------------Load table-------------------------
        QSqlQueryModel *model= new QSqlQueryModel ();
        Sconn.connect();
        QSqlQuery *queryload = new QSqlQuery(Sconn.getdata());
        QString view = "SELECT * FROM Staff" ;
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        Sconn.Disconnect();

}




void ManStaff::on_btnDelete_clicked()
{
    staff Sconn;
    QString username = ui->txtDeleteusername->text();
    if (username==NULL) {
        QMessageBox :: warning(this,"error","please enter username to delete") ;
    }
    else {
        Sconn.connect();
        QSqlQuery query ;
        QString del = " DELETE FROM Staff WHERE username='"+username+"'   ";
        query.prepare(del) ;
        if(query.exec()) {
            //QMessageBox :: warning(this,"successful","delete successful !") ;
        }
        Sconn.Disconnect();
    }
//----------------Load table----------------------
    QSqlQueryModel *model= new QSqlQueryModel ();
    Sconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Sconn.getdata());
    QString view = "SELECT * FROM Staff" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Sconn.Disconnect();
}




void ManStaff::on_btnUpdate_clicked()
{
    staff Sconn;
    QString updateusername = ui->txtUpdateusername->text();

    QString password = ui->txtNewpassword->text();
    QString name = ui->txtNewname->text();
    QString age = ui->txtNewage->text();
    if (updateusername == NULL || password==NULL || name ==NULL || age== NULL) {
        QMessageBox :: warning(this,"error","please fill out the form to update") ;
    }

    else {
        Sconn.connect();
        QSqlQuery query;
        QString update = " UPDATE Staff SET  password='"+password+"', name='"+name+"',age='"+age+"' WHERE username='"+updateusername+"'  ";

        query.prepare(update) ;
        if(query.exec()) {
           // QMessageBox :: warning(this,"successful","update successful !") ;
        }
        Sconn.Disconnect();
    }
    //----------------Load table----------------------
        QSqlQueryModel *model= new QSqlQueryModel ();
        Sconn.connect();
        QSqlQuery *queryload = new QSqlQuery(Sconn.getdata());
        QString view = "SELECT * FROM Staff" ;
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        Sconn.Disconnect();
}
