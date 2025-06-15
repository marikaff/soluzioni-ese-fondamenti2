#include <iostream>
using namespace std;

bool ese(const GrafoPesato& g){


    for (int i=0;i<g.n();i++){
        int somma_entranti=0;
        for (int j=0;j<g.n();j++){           
            somma_entranti+=g(j,i);
            if (g(j,i) && g.dep(j)<g.dep(i)){
                return false;}
            }

        if (somma_entranti>=g.dep(i)){
            return false;}
    }
    return true;
}

bool ese(const grafo& g){
    bool va_bene=false;

    for (int i=0;i<g.n();i++){
        int somma_entranti=0;
        for (int j=0;j<g.n() && i!=j;j++){
            somma_entranti+=g(j,i);
            if (g.dep(j)>=g.dep(i)){
                va_bene=true;}
            else {return false;}
        }

        if (somma_entranti<g.dep(i)){
            va_bene=true;}
        else {return false;}
    }
    return va_bene;
}