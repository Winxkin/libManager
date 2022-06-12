#ifndef MANBOOK_H
#define MANBOOK_H

#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include"staff.h"

namespace Ui {
class manbook;
}

class manbook : public QWidget
{
    Q_OBJECT

public:
    explicit manbook(QWidget *parent = 0);
    ~manbook();

private slots:
    void on_btnAdd_clicked();

    void on_btnupdate_clicked();

    void on_btndelete_clicked();

private:
    Ui::manbook *ui;
};

#endif // MANBOOK_H
