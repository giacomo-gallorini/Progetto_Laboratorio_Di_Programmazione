#include "Conto.h"
#include "Transazione.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Conto::Conto(float saldoIniziale){
    this->saldoIniziale = saldoIniziale;
}

Conto::~Conto(){}

void Conto::aggiungiTransazione(Transazione t){
    if(t.getTipo()==Transazione::tipoTransazione::USCITA && saldoAttuale < t.getValoreTransazione()){
#ifdef QT_DEBUG
        cout<<"Impossibile aggiungere transazione:saldo insufficiente per fare il prelievo richiesto!"<<endl;
#endif
    }
    else{
        numeroProgressivoId++;
        t.setId(numeroProgressivoId);
        transazioni.push_back(t);
        saldoAttuale = calcolaSaldo();
    }
}

float Conto::calcolaSaldo(){
    float s=saldoIniziale;
    for(int i=0;i<transazioni.size();i++){
        s+=transazioni[i].getValoreTransazione();
    }
#ifdef QT_DEBUG
    cout<<"numero transazioni "<<transazioni.size()<<endl;
#endif
    return s;
}

int Conto::getDimensioneVettore(){
    return transazioni.size();
}

vector <Transazione> Conto::getTransazioni(){
    return transazioni;
}

bool Conto::eliminaTransazione(unsigned int id){
    bool cancellazioneEffettuata=false;
    for(int i=transazioni.size()-1;i>=0;--i)
        if(transazioni[i].getId()==id){
            transazioni.erase(transazioni.begin()+i);
            cancellazioneEffettuata=true;
        }
    saldoAttuale = calcolaSaldo();
    return cancellazioneEffettuata;
}

Transazione Conto::cercaTransazione(unsigned int id){
    for(int i=0;i<transazioni.size();i++)
        if(transazioni[i].getId() == id)
            return transazioni[i];
    QDate data_casuale = QDate::currentDate();
    Transazione transazione_vuota(0," ",data_casuale,Transazione::tipoTransazione::TRANSAZIONE_VUOTA);
    return transazione_vuota;
}

vector<class Transazione> Conto::filtraTransazioni(string m){
    vector<Transazione> vettoreRisultato;
        for(int i=0;i<transazioni.size();i++){
            if(transazioni[i].getMotivazione()==m)
                vettoreRisultato.push_back(transazioni[i]);
        }
        return vettoreRisultato;
}

QString Conto::stampaTransazioni(vector<Transazione> t){
    QString buf=" ";
    QString b,m,id;
    for(int i=0;i<t.size();i++){
        b=QString::number(t[i].getValoreTransazione());
        m=QString::fromStdString(t[i].getMotivazione());
        id=QString::number(t[i].getId());
        QDate Mydate= t[i].getData();
        if(t[i].getTipo()==Transazione::tipoTransazione::USCITA)
            buf+="\n -Prelievo di "+b+" euro in data "+ QDate(Mydate).toString("dd-MMM-yyyy")+"\n Motivazione: "+m+"[ID transazione: "+id+"]";
        if(t[i].getTipo()==Transazione::tipoTransazione::ENTRATA)
            buf+="\n -Ricarica di "+b+" euro in data "+QDate(Mydate).toString("dd-MMM-yyyy")+"\n Motivazione: "+m+"[ID transazione: "+id+"]";
    }
    return buf;
}
