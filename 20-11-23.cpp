#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
//bool operator==(const prodotto& other){return nome==other.nome && prezzo==other.prezzo;}
using namespace::std;

class ricetta{
protected:
    string nome;
    unsigned tempo_prep;
    vector<string>ingredienti;
public:
    void set_nome(string nome){this->nome=nome;}
    void set_tempo_prep(unsigned tempo_prep){this->tempo_prep=tempo_prep;}
    void set_ingredienti(vector<string> ingredienti){this->ingredienti=ingredienti;}
    
    string get_nome() const {return nome;}
    unsigned get_tempo_prep() const {return tempo_prep;}
    vector<string> get_ingredienti() const {return ingredienti;}
    bool operator==(const ricetta& other){return nome==other.nome && tempo_prep==other.tempo_prep && ingredienti==other.ingredienti;}
};

class ricettario: public ricetta{
protected:
    vector<ricetta> libro_ricette;
public:
    
    bool aggiungiRicetta(const ricetta& r){
        libro_ricette.push_back(r);
        for (int i=0;i<libro_ricette.size();i++){
            if (libro_ricette[i]==r.get_nome()){
                return false;}}
        return true;}
    
//Preso in input un insieme di ingredienti, la funzione dovrà stampare, con opportuna
//re-definizione di std::ostream::operator<< per Ricetta, tutte le ricette che si
//possono prepare in meno di t minuti utilizzando solamente ingredienti contenuti in ingr.
    
    
    void svuotafrigo(const vector<string>& ingr, unsigned t, ricetta r){
        for (int i=0;i<libro_ricette.size();i++){
            for (int j=0;j<get_ingredienti().size();j++){
                if (get_tempo_prep()[i]<t && get_ingredienti()[i]==ingr[i]){
                    cout<<r;
                }
                    
                    
            }
        }
        
        
    }
    
    
};
