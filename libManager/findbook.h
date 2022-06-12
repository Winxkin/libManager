#ifndef FINDBOOK_H
#define FINDBOOK_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"


namespace Ui {
class findbook;
}

class findbook : public QWidget
{
    Q_OBJECT

public:
    explicit findbook(QWidget *parent = 0);
    ~findbook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::findbook *ui;
};

#endif // FINDBOOK_H
