#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include"manstaff.h"
#include"manmember.h"
#include"manbook.h"
#include"infostaff.h"
#include"bookdata.h"

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = 0);
    ~home();

private slots:


    void on_btnExitStaff_clicked();

    void on_managerStaff_clicked();

    void on_managerMem_clicked();

    void on_managerBook_clicked();

    void on_btnAbout_clicked();



    void on_btninfo_clicked();

    void on_btnbookdata_clicked();

private:
    Ui::home *ui;
    ManStaff Wmanstaff;
    manmember Wmanmember;
    manbook Wmanbook;
    infostaff Winfostaff;
    bookdata Wbookdata;

};

#endif // HOME_H
