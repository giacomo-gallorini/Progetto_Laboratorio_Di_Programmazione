#ifndef PRELIEVO_H
#define PRELIEVO_H

#include <QDialog>
#include "Transazione.h"
#include "Conto.h"

namespace Ui {
class UscitaView;
}

class UscitaView : public QDialog{
    Q_OBJECT

public:
    explicit UscitaView(Conto *c,QWidget *parent = nullptr);
    ~UscitaView();
    void writeOnly_on_file(float s);
    void readWrite_on_file(QString x,int id);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UscitaView *ui;
    Conto *conto;
};

#endif // PRELIEVO_H
