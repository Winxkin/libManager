#include "findbook.h"
#include "ui_findbook.h"

findbook::findbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findbook)
{
    ui->setupUi(this);
    setWindowTitle("Find book");
    //-------------------------------------
    staff FBconn;
    QSqlQueryModel *model= new QSqlQueryModel ();
    FBconn.connect();
    QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
    QString view = "SELECT * FROM Book" ;
    queryload->prepare(view);
    queryload->exec();
    model->setQuery(*queryload);
    ui->tableView->setModel(model);
    FBconn.Disconnect();
}

findbook::~findbook()
{
    delete ui;
}

void findbook::on_pushButton_clicked()
{
    staff FBconn;
    QString name = ui->txtname->text();
    QString author = ui->txtauthor->text();
    QString type = ui->txttype->text();

    if (name==NULL && author==NULL && type==NULL) {
        staff FBconn;
        QSqlQueryModel *model= new QSqlQueryModel ();
        FBconn.connect();
        QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
        QString view = "SELECT * FROM Book" ;
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        FBconn.Disconnect();
    }

    else {
        QSqlQueryModel *model= new QSqlQueryModel ();
        FBconn.connect();
        QSqlQuery *queryload = new QSqlQuery(FBconn.getdata());
        QString view = " SELECT * FROM Book WHERE Name='"+name+"' or Author='"+author+"' or Type='"+type+"' ";
        queryload->prepare(view);
        queryload->exec();
        model->setQuery(*queryload);
        ui->tableView->setModel(model);
        FBconn.Disconnect();
    }
}
