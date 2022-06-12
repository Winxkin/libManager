#ifndef BRETURN_H
#define BRETURN_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"


namespace Ui {
class breturn;
}

class breturn : public QWidget
{
    Q_OBJECT

public:
    explicit breturn(QWidget *parent = 0);
    ~breturn();

private slots:
    void on_btnview_clicked();

    void on_btnreturn_clicked();

private:
    Ui::breturn *ui;
};

#endif // BRETURN_H
