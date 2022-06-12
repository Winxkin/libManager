#ifndef INFOMEMBER_H
#define INFOMEMBER_H

#include <QWidget>
#include <QMessageBox>
#include<QSqlQuery>
#include <qdebug.h>
#include"staff.h"

namespace Ui {
class infomember;
}

class infomember : public QWidget
{
    Q_OBJECT

public:
    explicit infomember(QWidget *parent = 0);
    ~infomember();

private slots:
    void on_btnviewinfo_clicked();

    void on_btnchange_clicked();

private:
    Ui::infomember *ui;
};

#endif // INFOMEMBER_H
