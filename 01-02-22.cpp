#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace::std;

class gestore_valori{
protected:
    vector<pair<int,char>> coppie;
public:
     void inserisciCoppia(int a, char b){
        coppie.push_back({a,b});}
    
     double numCoppie() {
         return coppie.size();}
    
    virtual int getRisultato() const{
        return -1;}
};

//deve restituire la somma di tutti gli interi inseriti accoppiati al carattere ‘a’
//Se non è presente alcun valore associato al carattere ‘a’, restituire 0.

class gestore_valori_A: public gestore_valori{
public:
    int getRisultato() const override{
        int cont=0;
        
        for(int i=0;i<coppie.size();i++){
            if (coppie[i].second=='a'){
                cont+=coppie[i].first;}}
        if (cont==0){return 0;}
        else {return cont;}
        }};

//il metodo getRisultato() in GestoreValoriB deve calcolare la media (intera) degli interi inseriti
//accoppiati al carattere ‘b’. Se non è presente alcun valore associato al carattere ‘b’, restituire 0.

class gestore_valori_B: public gestore_valori{
public:
    int getRisultato() const override{
        int media=0;
        int cont=0;
        
        for(int i=0; i<coppie.size();i++){
            if (coppie[i].second=='b'){
                media+=coppie[i].first;
                cont++;}}
        if (cont==0){return 0;}
        else {return media/cont;}
    }};
