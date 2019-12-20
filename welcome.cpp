#include "welcome.h"
#include "ui_welcome.h"
#include "EntrataView.h"
#include "ContoView.h"
#include "UscitaView.h"
#include "Conto.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
using namespace std;

Welcome::Welcome(Conto *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{

    ui->setupUi(this);
    conto=c;
}

Welcome::~Welcome(){
    delete ui;
}

void Welcome::on_pushButton_clicked(){
    UscitaView p(conto);
    p.setModal(true);
    hide();
    p.exec();
}

void Welcome::on_pushButton_2_clicked(){
    EntrataView r(conto);
    r.setModal(true);
    hide();
    r.exec();
}

void Welcome::on_pushButton_3_clicked(){
    ContoView g(conto);
    g.setModal(true);
    hide();
    g.exec();
}

void Welcome::on_pushButton_4_clicked(){
    hide();
}
