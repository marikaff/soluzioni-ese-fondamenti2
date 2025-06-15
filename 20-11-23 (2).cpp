using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Ricetta{
    private:
        string nome;
        unsigned tempo_min;
        vector<string> ingredienti;
    public:
        string get_nome(){return nome;}
        unsigned get_tempo_min(){return tempo_min;}
        vector<string> get_ingredienti(){return ingredienti;}



};

class Ricettario:public Ricetta{
    protected:
        vector<Ricetta> ricettario;
    public:

        bool aggiungiRicetta(const Ricetta& r){
            for (int i=0;i<ricettario.size();i++){
                if  (ricettario[i].get_nome()==r){
                    return false;}
                else if (ricettario[i].get_nome()!=r){
                    ricettario.push_back(r);}}
            return true;}

        
        for(int i=0;i<get_ingredienti.size();i++){           
            ostream& operator<<(ostream& os) const{
                os<<
        }

        void svuotafrigo(const vector<string>& i, unsigned t){

        }











};
