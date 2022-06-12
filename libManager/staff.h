#ifndef STAFF_H
#define STAFF_H
#include<QString>
#include <QSqlDatabase>
#include <qdebug.h>
#include<QSqlQuery>
// NOTE: class staff is database include (Member,Staff,Book)
class staff
{
public:
    staff();
    ~staff();

    bool connect ();
    void Disconnect ();
    QSqlDatabase getdata();


private:
    QSqlDatabase data;
};

#endif // STAFF_H
