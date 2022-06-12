#include "borrow.h"
#include "ui_borrow.h"
#include"global_variable.h"
borrow::borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow)
{
    ui->setupUi(this);
    setWindowTitle("Borrow Book");
    //--------------load table-------------------------
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT * FROM Book" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->listbook->setModel(model);
    FBconn.Disconnect();
}

borrow::~borrow()
{
    delete ui;
}

void borrow::on_btnupdate_clicked()
{
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT book,date FROM Borrowbook WHERE username='"+gUsername+"' " ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->listborrow->setModel(model);
    FBconn.Disconnect();

}

void borrow::on_btnborrow_clicked()
{
       QString book=ui->txtbook->text();
        QString date=ui->txtdate->text();

       if(book==NULL || date==NULL)  QMessageBox :: warning(this,"error","please enter book and date") ;

       else {

                    staff conn;
                    conn.connect();


                   QSqlQuery query;
                   QString prepare = "SELECT Name From Book WHERE Name='"+book+"'  ";
                   query.prepare(prepare);


                   if (query.exec()) {
                       int c=0;
                       while (query.next()) c ++;
                       if (c == 1)   {
                           //excutive if it have

                                   QString add = "INSERT INTO Borrowbook (username,book,date) VALUES ('"+gUsername+"','"+book+"','"+date+"') ";
                                   query.prepare(add);
                                   query.exec();
                                    QMessageBox :: warning(this,"successful","Borrowing books successfully !") ;
                                    conn.Disconnect();

                       }
                       else {
                           QMessageBox :: warning(this,"error","Can find the book in the library") ;
                           conn.Disconnect();
                       }
                   }

            }

 //--------------------------laod table---------------------------------------------
       staff FBconn;
       QSqlQueryModel *model= new QSqlQueryModel ();
       FBconn.connect();
       QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
       QString view = "SELECT book,date FROM Borrowbook WHERE username='"+gUsername+"' " ;
       queryload->prepare(view);
       queryload->exec();
       model->setQuery(*queryload);
       ui->listborrow->setModel(model);
       FBconn.Disconnect();



}
