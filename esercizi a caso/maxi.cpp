#include <iostream>
#include <vector>
using namespace std;


class persona{
    private:
    string nome;
    string cognome;
    
    public:
    persona(){};
    persona(string nome,string cognome):nome(nome),cognome(cognome){};
    string getnome(){return nome;}
    string getcognome(){return cognome;}
    void setnome(string nome){this->nome=nome;}
    void setcognome(string cognome){this->cognome=cognome;}

    virtual int get_stipendio() const =0;
};

class studente: public persona{
    protected:
    int get_stipendio() const override{
        return 10;
    }
};

class impiegato: public persona{
    protected:
    int get_stipendio() const override{
        return 100;
    }
};


class gestorepersone{
    private:
    vector<persona*> persone;

    public:
    void aggiungipersona(persona* p){
        persone.push_back(p);
    }

    double getstipendiomedio(){
        double somma=0.0;

        for (auto it=persone.begin();it!=persone.end();it++){
            somma+=(*it)->get_stipendio();
        }
        return somma/persone.size();
    }




};