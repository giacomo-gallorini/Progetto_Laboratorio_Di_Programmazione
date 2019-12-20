#include "principale.h"
#include "ui_principale.h"
#include "welcome.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
using namespace std;

Principale::Principale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Principale)
{
    ui->setupUi(this);
    conto=new Conto(readOnly_on_file());
}

Principale::~Principale(){
    delete ui;
}

float Principale::readOnly_on_file(){
    QFile file1("C:/Users/giacomo/Documents/ProgProject/SaldoAttuale.txt");
    if(!file1.open(QFile::ReadOnly | QFile::Text)){
                QMessageBox::warning(this,"title","file not open");
            }
            QTextStream in(&file1);
            QString text=in.readAll();
            float saldoIniziale=text.toFloat();
            file1.close();
            return saldoIniziale;
}

void Principale::on_pushButton_clicked(){
    Welcome w(conto);
    w.setModal(true);
    hide();
    w.exec();
}
