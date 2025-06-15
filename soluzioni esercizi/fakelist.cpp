#include <iostream>
using namespace std;


//ESERCIZIO 1

class ese1{
    void func(char& a, char b){
        char c = a;
        a = b;
        b = c;}


    int main()
    {
        char* nome = new char[3]{'m','a','r'};

        cout << *(nome[1]) << endl; //da errore

        cout << *(nome + 2) << endl; //stampa r

        char* a = &nome[2];
        cout << *(a - 1) << endl; //stampa a

        char* nome_prof = new char[3]{'m','a','t'};
        func (nome_prof[0], nome_prof[1]);
        cout << nome_prof[0] << " " << nome_prof[1] << endl; //stampa a a
        


            return 0;
        }
};

//ESERCIZIO 2

class fakelist: public list<int>{
    public:

    int get_fake_size() const{
        return list<int>.size()*2;}

    void insert(int el){
        bool presente=false;
        for (auto it=list<int>.begin();it!=list<int>.end();it++){
            if (*it==el){presente=true;}
        }
        
        if (presente){list<int>.push_back(el);}
        if (!presente){list<int>.push_front(el);}}
    
    void fake_sort(bool s){
        list<int>.sort();

        if (!s){list<int>.reverse();}}

    void fake_clear(bool c){
        if (c){list<int>.clear();}
    }






};