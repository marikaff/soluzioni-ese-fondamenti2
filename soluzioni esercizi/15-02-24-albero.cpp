#include <iostream>
#include <vector>
#include "Albero_B.h"
using namespace std;

bool ese(const AlberoB<char>& a,vector<char>& s){
    if (a.nullo()){
        return false;}
    

    if (a.foglia()){
        s.push_back(a.radice());
        return true;}

    if (ese(a.figlio(SIN),s) || ese(a.figlio(DES),s)){
        return true;}

    return false;
}


bool fine(const AlberoB<char>& a){
    vector<char> v;
    ese(a,v);
    for (int i=0;i<v.size()-1;i++){
        if (v[i]>=v[i+1]){return false;}
    }
    return true;
    
}


void stampaAlbero(const AlberoB<char>& a, int livello) {
    if (a.nullo()) return;
    stampaAlbero(a.figlio(DES), livello + 1);
    for (int i = 0; i < livello; i++) cout << "  ";
    cout << a.radice() << endl;
    stampaAlbero(a.figlio(SIN), livello + 1);
}



int main() {
    AlberoB<char> a('A');

    AlberoB<char> b('B');
    AlberoB<char> c('C');
    AlberoB<char> d('D');
    AlberoB<char> e('E');
    AlberoB<char> f('F');
    AlberoB<char> g('G');

    a.insFiglio(SIN, b);
    a.insFiglio(DES, c);
    b.insFiglio(SIN, d);
    b.insFiglio(DES, e);
    c.insFiglio(SIN, f);
    c.insFiglio(DES, g);

    cout << "Albero di esempio:" << endl;
    stampaAlbero(a, 0);
    cout << endl;

    if (fine(a)) {
        cout << "L'albero è in ordine strettamente crescente!" << endl;
    } else {
        cout << "L'albero non è in ordine strettamente crescente!" << endl;
    }

    return 0;
}

