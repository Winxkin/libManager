#include "manbook.h"
#include "ui_manbook.h"

manbook::manbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manbook)
{
    ui->setupUi(this);
    setWindowTitle("Manage book");
    //-------------------------------------------------------
    staff Bconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    Bconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Bconn.getdata());
    QString view = "SELECT * FROM Book" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Bconn.Disconnect();
}

manbook::~manbook()
{
    delete ui;
}

void manbook::on_btnAdd_clicked()
{
    staff Bconn ;
    int flat=0;
     QString name = ui->txtname->text();
     QString author = ui->txtauthor->text();
     QString type = ui->txttype->text();


//-----------------------------------------------------------------------------------------------inspect Staff account
     if ( name == NULL || author==NULL || type==NULL ) {
         QMessageBox :: warning(this,"error","Please fill out the form") ;
         flat=1;
     }
     else {
             QSqlQuery qry;
             Bconn.connect();
             QString Bprepare1 = "SELECT Name From Book WHERE Name= :name   "   ;
             qry.prepare(Bprepare1);
             qry.bindValue(":name", name);

             if (qry.exec()) {
                 int c=0;
                 while (qry.next()) c ++;
                 if (c == 1)   {
                     QMessageBox :: warning(this,"error","Book already exists, please choose another book") ;

                     flat=1;
                 }

             }

     }
//-------------------------------------------------Add new staff account
  if (flat==1) Bconn.Disconnect();
  else {

     QSqlQuery query;
     Bconn.connect();
     QString Bprepare2 = "INSERT INTO Book (Name,Author,Type) VALUES ('"+name+"','"+author+"','"+type+"') ";
     query.prepare(Bprepare2);



     if (query.exec()) {
            QMessageBox :: warning(this,"successful","New book have been added") ;
            Bconn.Disconnect();
        }
        else {
            QMessageBox :: warning(this,"error","Can not addition!") ;
            Bconn.Disconnect();
        }
   }
  //------------Load table---------------------------------
  QSqlQueryModel *model= new QSqlQueryModel ();
  Bconn.connect();
  QSqlQuery *queryload = new QSqlQuery(Bconn.getdata());
  QString view = "SELECT * FROM Book" ;
  queryload->prepare(view);
  queryload->exec();
  model->setQuery(*queryload);
  ui->tableView->setModel(model);
  Bconn.Disconnect();
}

void manbook::on_btnupdate_clicked()
{
    staff Bconn;
    QString updatename = ui->txtupdatename->text();
    QString newname = ui->txtnewname->text();
    QString newauthor = ui->txtnewauthor->text();
    QString newtype = ui->txtnewtype->text();

    if (updatename == NULL || newname==NULL || newauthor==NULL || newtype==NULL )  QMessageBox :: warning(this,"error","please fill out the form to update") ;
    else {
        Bconn.connect();
        QSqlQuery query;
        QString update = " UPDATE Book SET Name='"+newname+"', Author='"+newauthor+"', Type='"+newtype+"'  WHERE Name='"+updatename+"'  ";

        query.prepare(update) ;
        query.exec();
        Bconn.Disconnect();
    }
    //------------Load table---------------------------------
    QSqlQueryModel *model= new QSqlQueryModel ();
    Bconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Bconn.getdata());
    QString view = "SELECT * FROM Book" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Bconn.Disconnect();
}

void manbook::on_btndelete_clicked()
{
    staff Bconn;
    QString name = ui->txtdelname->text();
    if (name==NULL) {
        QMessageBox :: warning(this,"error","please enter book name to delete") ;
    }
    else {
        Bconn.connect();
        QSqlQuery query ;
        QString del = " DELETE FROM Book WHERE Name='"+name+"'   ";
        query.prepare(del) ;
        query.exec();
        Bconn.Disconnect();
    }
    //------------Load table---------------------------------
    QSqlQueryModel *model= new QSqlQueryModel ();
    Bconn.connect();
    QSqlQuery *queryload = new QSqlQuery(Bconn.getdata());
    QString view = "SELECT * FROM Book" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    Bconn.Disconnect();
}
