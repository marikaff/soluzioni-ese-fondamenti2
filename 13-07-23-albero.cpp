#include <iostream>
#include "Albero_B.h"
#include <algorithm>
using  namespace std;

int ese(const AlberoB<string>& a){
    if (a.nullo()){return 0;}

    string x=a.radice();

    if (x=="*" || x=="/" || x=="+" || x=="-"){
        int sx=ese(a.figlio(SIN));
        int dx=ese(a.figlio(DES));
        
        if (x=="*"){return sx*dx;}
        else if (x=="/"){return sx/dx;}
        else if (x=="+"){return sx+dx;}
        else if (x=="-"){return sx-dx;}
    }

    return stoi(x);
    
}