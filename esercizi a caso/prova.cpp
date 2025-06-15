#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class esercizio{
    private:
    string descrizione;
    int difficolta;

    public:
    string get_descrizione(){return descrizione;}
    int getdifficolta(){return difficolta;}
}

class bancaDatiEsercizi:public esercizio{
    private:
    unordered_map<string, esercizio> bancaDati;
    public:
    bool aggiungiEsercizio(string id, esercizio e){

    }
    
}