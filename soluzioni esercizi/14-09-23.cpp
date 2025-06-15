#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace::std;

class esercizio{
private:
    string descrizione;
    int difficolta;
public:
    void set_descrizione (string descrizione){this->descrizione=descrizione;}
    void set_difficolta (int difficolta){this->difficolta=difficolta;}
    string get_descrizione(){return descrizione;}
    int get_difficolta(){return difficolta;}
    
};


class BancaDatiEsercizi{
private:
    unordered_map<esercizio, int> assegnazione;
    vector<string> vettore;
public:
    bool aggiungiEsercizio(string id, esercizio e){
        vettore.push_back(id);
        for (int i=0;i<vettore.size();i++){
            for (int j=0;j<vettore.size();j++){
                if (i!=j && vettore[i]==vettore[j]){
                    return false;}}}
        return true;}
    
   
            
    }
    
    
    
    
};
