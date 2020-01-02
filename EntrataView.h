#ifndef RICARICA_H
#define RICARICA_H

#include <QDialog>
#include "Transazione.h"
#include "Conto.h"

namespace Ui {
class EntrataView;
}

class EntrataView : public QDialog{
    Q_OBJECT

public:
    explicit EntrataView(Conto *c,QWidget *parent = nullptr);
    ~EntrataView();
    void writeOnly_on_file(float s);
    void readWrite_on_file(QString x,int id);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EntrataView *ui;
    Conto *conto;
};

#endif // RICARICA_H
