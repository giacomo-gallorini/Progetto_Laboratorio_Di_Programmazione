#ifndef CONTO_H
#define CONTO_H

#include <QString>
#include <QDate>
#include "vector"
using namespace std;

class Transazione;

class Conto{

public:
    Conto(float saldoIniziale);
    ~Conto();

    void aggiungiTransazione(Transazione t);
    float calcolaSaldo();
    int getDimensioneVettore();
    vector<Transazione> getTransazioni();
    bool eliminaTransazione(unsigned int id);
    Transazione cercaTransazione(unsigned int id);
    vector<Transazione> filtraTransazioni(string m);
    QString stampaTransazioni(vector <Transazione> t);

private:
    vector<Transazione> transazioni;
    float saldoIniziale;
    float saldoAttuale;
    unsigned int numeroProgressivoId=0;
};

#endif // CONTO_H
