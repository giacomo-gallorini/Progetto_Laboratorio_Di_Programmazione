#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "principale.h"
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);   
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    Principale welc;
    string str="user";
    string str1="password";
    QString qstr= QString::fromStdString(str);
    QString qstr1= QString::fromStdString(str1);
    if(ui->lineEdit->text()==qstr && ui->lineEdit_2->text()==qstr1){
        welc.setModal(true);
        hide();
        welc.exec();
    }
    else{
        QMessageBox box;
        box.setText("Invalid username or password");
        box.setWindowTitle("Accesso negato");
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        box.exec();
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1){
    if(arg1)
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
