#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace::std;


class prodotto { 
public:
    prodotto(string nome, double prezzo):nome(nome),prezzo(prezzo){};
    prodotto(const prodotto& other){
        this->nome=other.nome;
        this->prezzo=other.prezzo;};
    
    string get_nome() const{return nome;}
    double get_prezzo() const{return prezzo;}
    bool operator==(const prodotto& other){return nome==other.nome && prezzo==other.prezzo;}
private:
    string nome;
    double prezzo;
    };

class ListaDellaSpesa{ 
protected:
    unordered_map<prodotto, int> mappa;
public:
    void inserisci(const prodotto& p, int q){
        mappa[p]+=q;  //aggiungo la quantità al prodotto
        }

    
    bool rimuovi(const prodotto& p){
        for (auto it=mappa.begin();it!=mappa.end();it++){
            if ((it->first)==p){
                mappa.erase(it);
                return true;}
        }
            return false;}

    
    
    virtual double totale() const{
        double somma=0.0;
        for (auto it=mappa.begin();it!=mappa.end();it++){
            somma+=it->first.get_prezzo()*it->second;}
        return somma;
        }
    
};   

class lista_scontata:public ListaDellaSpesa{
public:
    double totale()const override{
        double somma=0.0;
        for (auto it=mappa.begin();it!=mappa.end();it++){
            if (it->first.get_prezzo()>5){
                somma+=it->first.get_prezzo()*0,75*it->second;}
            else {somma+=it->first.get_prezzo()*it->second;}}
        return somma;}
        
};
