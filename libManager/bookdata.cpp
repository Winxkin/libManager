#include "bookdata.h"
#include "ui_bookdata.h"

bookdata::bookdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookdata)
{
    ui->setupUi(this);
    setWindowTitle("Book loan data");
    //------------laod table--------------------
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT * FROM Borrowbook " ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    FBconn.Disconnect();
}

bookdata::~bookdata()
{
    delete ui;
}

void bookdata::on_btnfind_clicked()
{
    staff conn;
    QString username = ui->txtusername->text();
    QString book=ui->txtbook->text();
    QString date=ui->txtdate->text();

    if(username==NULL && book==NULL && date==NULL) {

        QSqlQueryModel *model= new QSqlQueryModel ();
        conn.connect();
        QSqlQuery *queryload = new QSqlQuery(conn.getdata());
        QString view = "SELECT * FROM Borrowbook " ;
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        conn.Disconnect();
    }
    else {
        QSqlQueryModel *model= new QSqlQueryModel ();
        conn.connect();
        QSqlQuery *queryload = new QSqlQuery(conn.getdata());
        QString view = "SELECT * From Borrowbook WHERE username='"+username+"' or book='"+book+"' or date='"+date+"'  ";
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        conn.Disconnect();

    }


}
