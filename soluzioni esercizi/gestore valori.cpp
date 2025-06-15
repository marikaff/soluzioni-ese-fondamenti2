#include <iostream>
using namespace std;


//ESERCIZIO 1

int esercizio_1(){


    int* mat=new int[6]{2,3,9,4,9,9};

    cout<<*(mat+3)<<" "<<*(mat+2);  //4 9
    cout<<*(mat[0]); //errore

    int& a=mat[4]; //a=9
    int b=mat[5];  //b=9
    --a;           //a=8, mat[4]=8
    b+=1;          //b=10
    cout<<mat[4]<<" "<<mat[5];  //8 e 9, perchè a è un alias, b no

    delete[] mat;





    return 0;
}


//ESERCIZIO 2

class gestorevalori{
    protected:
    vector<pair<int,char>> coppie;

    public:

    void inserisci_coppie(int a, char b){
        coppie.insert({a,b});}

    int num_coppie(){
        return coppie.size;}
    
    virtual int get_risultato() const{
        return -1;}
};

class gestorevalori_A: public gestorevalori{
    protected:

    int get_risultato() const override{
        int somma=0;

        for (int i=0;i<coppie.size();i++){
            if (coppie.second=='a'){
                somma+=coppie.first;}
        }}
};

class gestorevalori_B: public gestorevalori{
    protected:

    int get_risultato() const override{
        int media=0;
        int somma=0;
        
        for (int i=0;i<coppie.size();i++){
            if (coppie.second=='b'){
                somma+=coppie.first;
                media++;}
                };


    if (media=0){return 0;}
    
    return somma/media;}
};