#include "staff.h"
#define link_to_database "D:/QT project/libManager/Database.db"  //change link to database.
staff::staff()
{
    data = QSqlDatabase ::addDatabase("QSQLITE");
    data.setDatabaseName(link_to_database);
    qDebug()     << "Constructor" << endl;
    if (!data.open())  qDebug()     << "can not connect to database" << endl;
    else qDebug()     << "connect to database" << endl;
}

staff::~staff()
{

}

bool staff::connect (){
     qDebug() << "connected..." << endl;
    return data.open();
}

void staff::Disconnect (){
    qDebug() << "Disconnected..." << endl;
    data.close();
}

QSqlDatabase staff::getdata(){
    return data;
}
