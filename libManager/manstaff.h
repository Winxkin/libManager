#ifndef MANSTAFF_H
#define MANSTAFF_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"
namespace Ui {
class ManStaff;
}

class ManStaff : public QWidget
{
    Q_OBJECT

public:
    explicit ManStaff(QWidget *parent = 0);
    ~ManStaff();


private slots:
    void on_btnADD_clicked();



    void on_btnDelete_clicked();

    void on_btnUpdate_clicked();

private:
    Ui::ManStaff *ui;
};

#endif // MANSTAFF_H
