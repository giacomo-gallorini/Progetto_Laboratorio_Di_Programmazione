#ifndef PRINCIPALE_H
#define PRINCIPALE_H

// Pagina di benvenuto

#include <QDialog>
#include "Conto.h"

namespace Ui {
class Principale;
}

class Principale : public QDialog{
    Q_OBJECT

public:
    explicit Principale(QWidget *parent = nullptr);
    ~Principale();
    float readOnly_on_file();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Principale *ui;
    Conto *conto;
};

#endif // PRINCIPALE_H
