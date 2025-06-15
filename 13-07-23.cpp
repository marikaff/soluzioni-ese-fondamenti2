#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Spedizione{
    private:
    int codice;
    float valore;
    float peso;

    public:
    int getCodice() const{return codice;}
    float getValore() const{return valore;}
    float getPeso() const{return peso;}

    friend ostream& operator<<(ostream& os, const Spedizione& sp){
        os<<"codice: "<< sp.codice<<" valore: "<<sp.valore<<" peso: "<<sp.peso;
        return os;
    }

    bool operator==(const Spedizione& other)const {
        return (codice==other.codice) && (valore==other.valore) && (peso==other.peso);
    }
    
};

class CodaSpedizioni{
    private:
    list<Spedizione*> lista;

    public:
    void add(Spedizione* sp){
        for (auto it=lista.begin();it!=lista.end();it++){
            if (**it==*sp){return;}
        }
        //si ordinano prima per peso, poi per valore e infine per codice
       lista.push_back(sp);

        //LAMBDA
       lista.sort([](Spedizione* a, Spedizione* b) {
        if (a->getPeso() != b->getPeso())
            return a->getPeso() < b->getPeso();  // Ordina per peso
        if (a->getValore() != b->getValore())
            return a->getValore() < b->getValore();  // Ordina per valore se peso è uguale
        return a->getCodice() < b->getCodice();  // Ordina per codice se peso e valore sono uguali
        });
    }

    Spedizione* next() const{
        if (!lista.empty()){return;}

        return lista.back();
    }

    void remove(){
        lista.pop_back();
    }

    unsigned int size() const{
        return lista.size();
    }



};
