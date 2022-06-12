#ifndef MANMEMBER_H
#define MANMEMBER_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"

namespace Ui {
class manmember;
}

class manmember : public QWidget
{
    Q_OBJECT

public:
    explicit manmember(QWidget *parent = 0);
    ~manmember();

private slots:


    void on_btnadd_clicked();

    void on_btnupdate_clicked();

    void on_btndelete_clicked();

private:
    Ui::manmember *ui;
};

#endif // MANMEMBER_H
