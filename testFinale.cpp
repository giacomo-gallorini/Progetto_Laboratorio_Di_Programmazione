#include <QString>
#include <QDate>
#include <QtTest>
#include "stdio.h"
#include <iostream>
#include "Conto.h"
#include "Transazione.h"

class testFinale:public QObject{
    Q_OBJECT

public:
    testFinale();
    private Q_SLOTS:
    void Test_calcolaSaldo();
    void Test_aggiungiTransazione();
    void Test_eliminaTransazione();
    void Test_cercaTransazione();
};
testFinale::testFinale(){}

void testFinale::Test_calcolaSaldo(){
    Conto* conto = new Conto(95);
    QDate data = QDate::currentDate();
    int trans_1 = 10;
    int trans_2 = 5;
    Transazione prelievo(trans_2," ",data,Transazione::tipoTransazione::USCITA); //prelievo
    Transazione ricarica(trans_1," ",data,Transazione::tipoTransazione::ENTRATA); //ricarica
    conto->aggiungiTransazione(prelievo);
    conto->aggiungiTransazione(ricarica);
    float new_saldo = conto->calcolaSaldo();
    QCOMPARE(100,new_saldo);
}

void testFinale::Test_aggiungiTransazione(){
    Conto *conto = new Conto(100);
    QDate data = QDate::currentDate();
    Transazione prelievo(100," ",data,Transazione::tipoTransazione::USCITA); //prelievo
    Transazione ricarica(50," ",data,Transazione::tipoTransazione::ENTRATA); //ricarica
    conto->aggiungiTransazione(prelievo);
    conto->aggiungiTransazione(ricarica);
    float new_saldo = conto->calcolaSaldo();
    int numeroTransazioni = conto->getDimensioneVettore();
    QCOMPARE(50,new_saldo);
    QCOMPARE(2,numeroTransazioni);

    // Tentativo di aggiungere una transazione già aggiunta precedentemente
    conto->aggiungiTransazione(prelievo);
    QCOMPARE(50,new_saldo);     // Il saldo rimane invariato
    QCOMPARE(2,numeroTransazioni); // Il numero di transazioni rimane invariato

    // Tentativo di aggiungere una transazione in uscita(prelievo) di importo superiore al saldo disponibile
    Transazione prelievo_eccessivo(100," ",data,Transazione::tipoTransazione::USCITA);
    conto->aggiungiTransazione(prelievo_eccessivo);
    QCOMPARE(50,new_saldo);     // Il saldo rimane invariato
    QCOMPARE(2,numeroTransazioni); // Il numero di transazioni rimane invariato
}

void testFinale::Test_eliminaTransazione(){
    bool cancellazioneAvvenuta;
    float new_saldo = 0;
    int numeroTransazioni;
    Conto *conto = new Conto(100);
    QDate data=QDate::currentDate();

    // Primo caso: ancora nessuna transazione è stata creata
    new_saldo = conto->calcolaSaldo();
    numeroTransazioni = conto->getDimensioneVettore();
    cancellazioneAvvenuta = conto->eliminaTransazione(1);
    QCOMPARE(false,cancellazioneAvvenuta);
    QCOMPARE(100,new_saldo);
    QCOMPARE(0,numeroTransazioni);

    // Vengono create due transazioni e aggiunte al vettore di transazioni del conto
    Transazione prelievo(100," ",data,Transazione::tipoTransazione::USCITA); //prelievo. ID=1
    Transazione ricarica(50," ",data,Transazione::tipoTransazione::ENTRATA); //ricarica. ID=2
    conto->aggiungiTransazione(prelievo);
    conto->aggiungiTransazione(ricarica);

    //Secondo caso: si cerca di eliminare una transazione con ID inesistente
    new_saldo = conto->calcolaSaldo();
    numeroTransazioni = conto->getDimensioneVettore();
    cancellazioneAvvenuta = conto->eliminaTransazione(3);
    QCOMPARE(false,cancellazioneAvvenuta);
    QCOMPARE(50,new_saldo);
    QCOMPARE(2,numeroTransazioni);

    //Terzo caso: si cerca di eliminare una transazione con ID esistente
    cancellazioneAvvenuta = conto->eliminaTransazione(2);
    new_saldo = conto->calcolaSaldo();
    numeroTransazioni = conto->getDimensioneVettore();
    QCOMPARE(true,cancellazioneAvvenuta);
    QCOMPARE(0,new_saldo);
    QCOMPARE(1,numeroTransazioni);
}

void testFinale::Test_cercaTransazione(){
    Conto *conto = new Conto(0);
    QDate data = QDate::currentDate();

    //Primo caso: si cerca una transazione quando ancora il vettore delle transazioni è vuoto
    Transazione transazioneCercata = conto->cercaTransazione(1);
    QCOMPARE(Transazione::tipoTransazione::TRANSAZIONE_VUOTA,transazioneCercata.getTipo());

    // Vengono create due transazioni e aggiunte al vettore di transazioni del conto
    Transazione prelievo(0," ",data,Transazione::tipoTransazione::USCITA); //prelievo. ID=1
    Transazione ricarica(0," ",data,Transazione::tipoTransazione::ENTRATA); //ricarica. ID=2
    conto->aggiungiTransazione(prelievo);
    conto->aggiungiTransazione(ricarica);

    //Secondo caso: si cerca una transazione con ID inesistente
    transazioneCercata = conto->cercaTransazione(3);
    QCOMPARE(Transazione::tipoTransazione::TRANSAZIONE_VUOTA,transazioneCercata.getTipo());
}



QTEST_APPLESS_MAIN(testFinale)

#include "testFinale.moc"
