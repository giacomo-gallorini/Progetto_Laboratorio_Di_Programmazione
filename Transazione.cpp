#include "Transazione.h"
#include "Conto.h"
using namespace std;

Transazione::Transazione(float valore_transazione, string motivazione, QDate data, tipoTransazione t){
    this->motivazione = motivazione;
    this->data = data;
    this->tipo = t;
    if(this->tipo == tipoTransazione::USCITA) // è un prelievo
        this->valore_transazione = -valore_transazione;
    else //è una ricarica
        this->valore_transazione = valore_transazione;
}

Transazione::~Transazione(){}

string Transazione::getMotivazione(){
    return motivazione;
}

void Transazione::setMotivazione(string nuovaMotivazione){
    motivazione = nuovaMotivazione;
}

QDate Transazione::getData(){
    return data;
}

void Transazione::setData(QDate nuovaData){
    data = nuovaData;
}

float Transazione::getValoreTransazione(){
    return valore_transazione;
}

Transazione::tipoTransazione Transazione::getTipo(){
    return tipo;
}

unsigned int Transazione::getId(){
    return id;
}

void Transazione::setId(unsigned int i){
    if(id == 0)
        id = i;
}

