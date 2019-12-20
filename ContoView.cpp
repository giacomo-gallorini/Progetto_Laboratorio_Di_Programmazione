#include "ContoView.h"
#include "ui_ContoView.h"
#include "welcome.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include <iostream>
#include <cstdlib>
using namespace std;

ContoView::ContoView(Conto *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContoView)
{
    ui->setupUi(this);
    conto=c;

    QString text=QString::number(conto->calcolaSaldo());
    ui->label->setText("Saldo attuale: €"+text);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setPlainText(readOnly_on_file());
    ui->comboBox->addItem("Tutte le transazioni");
    ui->comboBox->addItem("Svago");
    ui->comboBox->addItem("Lavoro");
    ui->comboBox->addItem("Spese rimborsabili");
    ui->comboBox->addItem("Stipendio");
    ui->comboBox->addItem("Bonifico");
    ui->comboBox->addItem("Rimborsi");
    ui->comboBox->addItem("Deposito");
}

ContoView::~ContoView(){
    delete ui;
}

void ContoView::on_pushButton_clicked(){
    Welcome w(conto);
    w.setModal(true);
    hide();
    w.exec();
}

QString ContoView::readOnly_on_file(){
    QFile file1("C:/Users/giacomo/Documents/ProgProject/Transazioni.txt");
    if(!file1.open(QFile::ReadOnly | QFile::Text)){
                QMessageBox::warning(this,"title","file not open");
            }
            QTextStream in2(&file1);
            QString text1=in2.readAll();
            return text1;
}

void ContoView::on_comboBox_currentIndexChanged(const QString &arg1){
    string c=arg1.toStdString();
    if(c=="Tutte le transazioni")
        ui->plainTextEdit->setPlainText(conto->stampaTransazioni(conto->getTransazioni()));
    else{
    vector<Transazione *> v=conto->filtraTransazioni(c);
    ui->plainTextEdit->setPlainText(conto->stampaTransazioni(v));
    }
}

void ContoView::on_pushButton_2_clicked(){
    QMessageBox box;
    box.setWindowTitle("Avviso");
    QString x = ui->lineEdit->text();
    int id = x.toInt();
    bool cancellazioneEffettuata=conto->eliminaTransazione(id);
    if(cancellazioneEffettuata == true){
        QString text=QString::number(conto->calcolaSaldo());
        ui->label->setText("Saldo attuale: €"+text);
        QString buf = conto->stampaTransazioni(conto->getTransazioni());
        QByteArray nuovaCronologiaTransazioni=buf.toUtf8();
        QFile file("C:/Users/giacomo/Documents/ProgProject/Transazioni.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
            file.write(nuovaCronologiaTransazioni);
        }
        box.setText("Transazione eliminata con successo!");
    }
    else
        box.setText("Nessuna transazione corrisponde all'ID selezionato");
    ui->lineEdit->setText(" ");
    if(ui->comboBox->currentIndex() == 0)
        ui->comboBox->setCurrentIndex(1);
    ui->comboBox->setCurrentIndex(0);
    box.exec();
}
