#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace::std;
 
class veicolo {
private:
    string targa;
    double prezzo;
    string marca;
    
public:
    veicolo (string targa, double prezzo, string marca):targa(targa),prezzo(prezzo),marca(marca){};
    veicolo (const veicolo& other){
        this->targa=other.targa;
        this->prezzo=other.prezzo;
        this->marca=other.marca;}
    string get_targa()const{return targa;}
    double get_prezzo()const{return prezzo;}
    string get_marca()const{return marca;}
    
    virtual double prezzoFinale() const=0;
    

};

class Auto:public veicolo{
public:
    Auto(string targa, double prezzo, string marca): veicolo(targa, prezzo, marca) {}
    double prezzoFinale() const override{
        return get_prezzo()*25/100;
    }
};


class Moto:public veicolo{
public:
    Moto(string targa, double prezzo, string marca): veicolo(targa, prezzo, marca) {}
    double prezzoFinale() const override{
        return get_prezzo()*15/100;
    }
};


int main(){
    vector<*veicolo> mezzi;
    string tipo;
    cout<<"scegli il tipo di veicolo o digita fine per uscire:";
    cin>>tipo;
    
    while (tipo!="fine"){
        string targa;
        double prezzo;
        string marca;
        
        cout<<"scrivi targa, prezzo, marca";
        cin>>targa>>prezzo>>marca;
        
        if (tipo=="auto"){
            mezzi.push_back(new Auto(targa,prezzo,marca));
        }
        if (tipo=="moto"){
            mezzi.push_back(new Moto(targa,prezzo,marca));
        }
       

     
            
            }
    
    return 0;
    
}
    
    
    
    
