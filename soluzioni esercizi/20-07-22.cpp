#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

class persona{
private:
    string nome;
    string cognome;
public:
    persona(string nome,string cognome): nome(nome), cognome(cognome){}; //costruttore con parametri
    persona(){};         //costruttore senza parametri
    
    void set_nome(string nome){this->nome=nome;}
    void set_cognome(string cognome){this->cognome=cognome;}
    string get_nome(){return nome;}
    string get_cognome(){return cognome;}

    virtual int get_stipendio() const = 0;
};

class studente:public persona{
public:
    int get_stipendio(){return 10;}};


class impiegato:public persona{
public:
    int get_stipendio(){return 100;}};

class gestore_persone{
private:
    vector<persona*> persone;  //vettore di puntatori a persone
    void aggiungi_persona(persona* p){
        persone.push_back(p);}
    
    double getStipendioMedio(){
        int cont=0;
        int somma=0;
        for (auto it=persone.begin();it!=persone.end();it++){
            somma+=(*it)->get_stipendio(); //->serve per arrivare a degli elementi dell'oggetto puntato
            cont++;}
        return somma/cont;}
};
