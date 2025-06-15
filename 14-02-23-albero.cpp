#include "albero.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool esercizio3 (const AlberoB<int> a, int x, vector<int>& cammino){
    if (a.nullo()){
        return false;}
    
    cammino.push_back(a.radice());
    
    if (a.foglia() && a.radice()==x){
        return true;}
    
    if (esercizio3(a.figlio(SIN),x,cammino) || esercizio3(a.figlio(DES),x,cammino)){
        return true;}
    
    cammino.pop_back();
    return false;
}

int stampa(const AlberoB<int> a, int x){
    vector<int> cammino;
    if (!esercizio3(a,x,cammino)){
        return -1;}
    else{
        for (int i=0; i<cammino.size();i++){
            cout<<cammino[i];}
    }
}
