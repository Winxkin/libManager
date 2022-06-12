#ifndef INFOSTAFF_H
#define INFOSTAFF_H

#include <QWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include <qdebug.h>
#include"staff.h"

namespace Ui {
class infostaff;
}

class infostaff : public QWidget
{
    Q_OBJECT

public:
    explicit infostaff(QWidget *parent = 0);
    ~infostaff();

private slots:
     void on_btnchange_clicked();

     void on_btnviewinfo_clicked();

private:
    Ui::infostaff *ui;
};

#endif // INFOSTAFF_H
