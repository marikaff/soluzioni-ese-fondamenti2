#include <iostream>
#include <list>
#include <algorithm>
using namespace::std;

class FakeList{
protected:
    list<int> lista;
public:
    
    double getFakeSize() const{
        return lista.size()*2;}
    
    void insert(int el){
        bool esiste=false;
        for (auto it=lista.begin();it!=lista.end();it++){
            if ((*it)==el){esiste=true;}}
        
        if (esiste) {lista.push_back(el);}
        else {lista.push_front(el);}}
    
    void fakeSort(bool s){
        if (s){lista.sort();}
        if (!s){lista.sort();
            lista.reverse();}}
    
    void fakeClear(bool c){
        if (c){lista.clear();}}
    
};
