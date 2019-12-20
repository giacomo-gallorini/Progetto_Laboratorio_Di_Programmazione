#ifndef TRANSAZIONI_H
#define TRANSAZIONI_H

#include <QString>
#include <QDate>
using namespace  std;

class Conto;

class Transazione{

public:
    enum class tipoTransazione{
        USCITA,
        ENTRATA
    };
    Transazione(float valore_transazione,string motivazione,QDate data,tipoTransazione t);

    string getMotivazione();
    void setMotivazione(string nuovaMotivazione);
    QDate getData();
    void setData(QDate nuovaData);
    float getValoreTransazione();
    tipoTransazione getTipo();
    unsigned int getId();
    void setId(unsigned int i);

private:
    string motivazione;
    QDate data;
    tipoTransazione tipo;
    float valore_transazione;
    unsigned int id=0; // identificatore univoco per ogni transazione
};

#endif // TRANSAZIONI_H
