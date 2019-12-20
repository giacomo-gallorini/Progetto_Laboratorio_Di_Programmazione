#ifndef GESTIONE_H
#define GESTIONE_H

#include <QDialog>
#include <QString>
#include "Conto.h"
#include "Transazione.h"

namespace Ui {
class ContoView;
}

class ContoView : public QDialog{
    Q_OBJECT

public:
    explicit ContoView(Conto *c,QWidget *parent = nullptr);
    ~ContoView();
    QString readOnly_on_file();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::ContoView *ui;
    Conto *conto;
};

#endif // GESTIONE_H
