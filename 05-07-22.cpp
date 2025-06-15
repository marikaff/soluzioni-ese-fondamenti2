#include <iostream>
using namespace std;


//!CODICE CON ARRAY DINAMICO COME RICHIESTO DALLA TRACCIA

class carriera{
    private:
    int numAppelli;
    bool* esiti;
    string* nomiEsami;

    public:
    carriera():numAppelli(0),esiti(nullptr),nomiEsami(nullptr){};
    carriera(const carriera& other){
        this->numAppelli=other.numAppelli;
        esiti=new bool[numAppelli];
        nomiEsami=new string[numAppelli];
        for (int i=0;i<numAppelli;i++){
            this->esiti[i]=other.esiti[i];
            this->nomiEsami[i]=other.nomiEsami[i];
        }
    }

    ~carriera(){delete[] esiti; delete[] nomiEsami;}

    carriera& operator=(const carriera& other){
        if (this==&other){return *this;}
        numAppelli=other.numAppelli;
        esiti=new bool[numAppelli];
        nomiEsami=new string[numAppelli];
        for (int i=0;i<numAppelli;i++){
            esiti[i]=other.esiti[i];
            nomiEsami[i]=other.nomiEsami[i];
        }
        return *this;
    }

    void aggiungi_tentativo(string nome, bool esito){

        bool* tmp_esiti=new bool[numAppelli+1];
        string* tmp_nomi=new string[numAppelli+1];
        for (int i=0;i<numAppelli;i++){
            tmp_esiti[i]=esiti[i];
            tmp_nomi[i]=nomiEsami[i];
        }
        tmp_esiti[numAppelli]=esito;
        tmp_nomi[numAppelli]=nome;
        delete [] esiti;
        delete [] nomiEsami;
        esiti=tmp_esiti;
        nomiEsami=tmp_nomi;
        numAppelli++;
    }

    void rimuovi_ultimo_appello(){
        if (numAppelli>0){
            bool* tmp_esiti=new bool[numAppelli-1];
            string* tmp_nomi=new string[numAppelli-1];

            for (int i=0;i<numAppelli-1;i++){
                tmp_esiti[i]=esiti[i];
                tmp_nomi[i]=nomiEsami[i];}
            delete[] esiti;
            delete[] nomiEsami;
            esiti=tmp_esiti;
            nomiEsami=tmp_nomi;
            numAppelli--;}
    }

    bool studenteDiligente(){
        int pos=0;
        int neg=0;
        for (int i=0;i<numAppelli;i++){
            if (esiti[i]==true){pos++;}
            else{neg++;}}
        
        return (pos>neg);
    }



};


int main(){
    carriera c;
    c.aggiungi_tentativo("fisica",false);
    c.aggiungi_tentativo("analisi",false);
    c.aggiungi_tentativo("economia",true);

    c.rimuovi_ultimo_appello();

    bool x=c.studenteDiligente();

    if (x){cout<<"si";}
    else{cout<<"cretino!!!!!!!";}



    return 0;
}






//! CODICE CON VETTORE

// class carriera{
// private:
//     int num_appelli;
//     vector<bool>esiti; //vettore di bool, true->passato, false->bocciato
//     vector<string> nomi_esami; //vettore di stringhe dove la i è il nome dell'esame sostenuto
// public:
//     carriera(){    //costruttore di base
//         int num_appelli=0;
//         vector<bool> esiti = vector<bool>(num_appelli);
//         vector<string> nomi_esami= vector<string>(num_appelli);}
    
//     carriera(const carriera& other){ //costruttore di copia
//         this->num_appelli=other.num_appelli;
//         num_appelli=other.num_appelli;
//         this->esiti=other.esiti;
//         this->nomi_esami=other.nomi_esami;}
    
// //    IL DISTRUTTORE SI USA SOLO CON ARRAY DINAMICI E PUNTATORI
// //    char* array=new char[6]{};   costruttore di un array di char, new=dinamica
// //    int* num=new int(3);
// //    ~carriera(){
// //        delete []array;
// //        delete num;
// //    }
// //    

   
//  operatore di assegnamento


//     void aggiungi_tentativo(string nome, bool esito){
//         esiti.push_back(esito);
//         nomi_esami.push_back(nome);}
    
//     void rimuovi_ultimo_appello(){
//         esiti.pop_back();
//         nomi_esami.pop_back();}
    
//     bool studente_diligente(){
//         int cont_pos=0;
//         int cont_neg=0;
//         for (auto it=esiti.begin();it!=esiti.end();it++){
//             if ((*it)==true){cont_pos++;}
//             else{cont_neg++;}}
//         if (cont_pos>cont_neg){return true;}
//         else{return false;}}
  
// };
