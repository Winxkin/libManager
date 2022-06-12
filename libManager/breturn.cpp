#include "breturn.h"
#include "ui_breturn.h"
#include "global_variable.h"


breturn::breturn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::breturn)
{
    ui->setupUi(this);
    setWindowTitle("Return book");

}

breturn::~breturn()
{
    delete ui;
}

void breturn::on_btnview_clicked()
{
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT book,date FROM Borrowbook WHERE username='"+gUsername+"' " ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    FBconn.Disconnect();
}

void breturn::on_btnreturn_clicked()
{
    QString book=ui->txtbook->text();
    QString date=ui->txtdate->text();
    if(book==NULL || date==NULL)  {
        QMessageBox :: warning(this,"error","please enter book and date") ;

      }
    else {
    staff conn;
    QSqlQuery query;
    conn.connect();
    QString prepare = "SELECT * From Borrowbook WHERE username='"+gUsername+"' and book='"+book+"' and date='"+date+"'  ";
    query.prepare(prepare);
    if(query.exec()) {

                    QString del ="DELETE FROM Borrowbook WHERE username='"+gUsername+"' and book='"+book+"' and date='"+date+"'  ";
                   query.prepare(del);
                    if(!query.exec()) {
                        QMessageBox :: warning(this,"error","can not return book") ;
                    }


      }
    else QMessageBox :: warning(this,"error","can find the book") ;

        conn.Disconnect();
     }
    //---------------------------------------------------------------
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT book,date FROM Borrowbook WHERE username='"+gUsername+"' " ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    FBconn.Disconnect();

}
