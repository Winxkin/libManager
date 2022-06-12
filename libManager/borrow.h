#ifndef BORROW_H
#define BORROW_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"


namespace Ui {
class borrow;
}

class borrow : public QWidget
{
    Q_OBJECT

public:
    explicit borrow(QWidget *parent = 0);
    ~borrow();

private slots:
    void on_btnupdate_clicked();

    void on_btnborrow_clicked();

private:
    Ui::borrow *ui;
};

#endif // BORROW_H
