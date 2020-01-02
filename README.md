# Progetto_Laboratorio_Di_Programmazione
Nuovi commit:
- Codice riformattato
- I messaggi all'interno dei metodi aggiungiTransazione() e calcolaSaldo() della classe Conto, nel file conto.cpp, vengono stampati in output solo compilando in modalità Debug e non Release, grazie all'utilizzo della macro QT_DEBUG
- L'attributo 'tipo' della classe Transazione, che definisce una transazione come entrata(ricarica) o uscita(prelievo), non è più di tipo 'unsigned int' bensì una enumerazione
- Il vettore della classe Conto non è più di puntatori a Transazione ma di oggetti Transazione.
