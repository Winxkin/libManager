#ifndef MEMHOME_H
#define MEMHOME_H

#include <QWidget>
#include<QPixmap>
#include"findbook.h"
#include"infomember.h"
#include"borrow.h"
#include"breturn.h"
namespace Ui {
class MemHome;
}

class MemHome : public QWidget
{
    Q_OBJECT

public:
    explicit MemHome(QWidget *parent = 0);
    ~MemHome();

private slots:


    void on_btnExitmem_clicked();

    void on_btnfindbook_clicked();

    void on_btnabout_clicked();

    void on_btninfo_clicked();

    void on_btnbrrowbook_clicked();

    void on_btnreturnbook_clicked();

private:
    Ui::MemHome *ui;
    findbook Wfindbook;
    infomember Winfomember;
     borrow Wborrow;
     breturn Wbreturn;
};

#endif // MEMHOME_H
