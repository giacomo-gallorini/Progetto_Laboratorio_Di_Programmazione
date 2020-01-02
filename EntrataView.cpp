#include "EntrataView.h"
#include "ui_EntrataView.h"
#include "welcome.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QIntValidator>
#include <QString>
#include <QDate>
using namespace std;

EntrataView::EntrataView(Conto *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntrataView)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(1,250,this));
    conto=c;
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox->addItem("Stipendio");
    ui->comboBox->addItem("Bonifico");
    ui->comboBox->addItem("Rimborsi");
    ui->comboBox->addItem("Deposito");
}

EntrataView::~EntrataView(){
    delete ui;
}

void EntrataView::on_pushButton_clicked(){
    QMessageBox box;
    QString x=ui->lineEdit->text();
    double prel=x.toDouble();
    string m=ui->comboBox->currentText().toStdString();

    Transazione pE(prel,m,ui->dateEdit->date(),Transazione::tipoTransazione::ENTRATA);
    conto->aggiungiTransazione(pE);

    float saldoAttuale=conto->calcolaSaldo();

    //Aggiorno il valore del saldo sul file di testo

    writeOnly_on_file(saldoAttuale);

    // Aggiungo le info relative all'ultima transazione effettuata(prelievo,saldo aggiornato,data)

    readWrite_on_file(x,pE.getId());

    box.setText("Ricarica avvenuta con successo");
    box.setWindowTitle(" ");
    ui->lineEdit->setText("");
    box.exec();
}

void EntrataView::on_pushButton_2_clicked(){
    Welcome w(conto);
    w.setModal(true);
    hide();
    w.exec();
}

void EntrataView::writeOnly_on_file(float s){
    QFile file1("C:/Users/giacomo/Documents/ProgProject/SaldoAttuale.txt");
    if(!file1.open(QFile::WriteOnly | QFile::Text)){
                QMessageBox::warning(this,"title","file not open");
            }
            QTextStream out(&file1);
            QString text=QString::number(s);
            out<<text;
            file1.flush();
            file1.close();
}

void EntrataView::readWrite_on_file(QString x,int id){
    QFile file("C:/Users/giacomo/Documents/ProgProject/Transazioni.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QByteArray buf=x.toUtf8()+" euro";
        QString i=QString::number(id);
        QByteArray bufID=i.toUtf8();
        buf += file.readAll();
        file.seek(0);
        QDate Mydate= ui->dateEdit->date();
        QString dateString=Mydate.toString();
        QByteArray data=dateString.toUtf8();
        file.write("\n -Effettuata ricarica (ID:"+bufID+") in data "+data+"\n Motivazione: "+" di "+buf);
    }
}
