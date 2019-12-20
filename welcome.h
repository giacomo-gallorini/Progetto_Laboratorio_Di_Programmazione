#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "Conto.h"

namespace Ui {
class Welcome;
}

class Welcome : public QDialog{
    Q_OBJECT

public:
    explicit Welcome(Conto *c,QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Welcome *ui;
    Conto *conto;
};

#endif // WELCOME_H
