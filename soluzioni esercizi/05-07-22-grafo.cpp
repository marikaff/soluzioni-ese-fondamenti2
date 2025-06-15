#include <iostream>
#include 'grafo.h'
using namespace std;

void ese(const grafo & g, int k1, int k2){
    bool controllo=false;

    for (int i=0;i<g.n();i++){
        int archi_entranti=0;
        int somma_entranti=0;
        int archi_uscenti=0;
        int somma_uscenti=0;

        for (int j=0;j<g.n();j++){
            if (g(i,j) || g(j,i)){
                if (g.transfer(i,j)>=k1 && g.transfer(i,j)<=k2){
                    archi_entranti++;
                    somma_entranti+=g.transfer(i,j);}

                else if (g.transfer(j,i)>=k1 && g.transfer(j,i)<=k2){
                    archi_uscenti++;
                    somma_uscenti+=g.transfer(j,i);}

                else {cout<<"NO";}
            }
        }

        if (archi_entranti%2==0 && somma_entranti<=somma_uscenti){
            controllo=true;}
        if (archi_entranti%2!=0 && somma_entranti>=somma_uscenti){
            controllo=true;}
        if (archi_entranti==0 || archi_uscenti==0){
            controllo=true;}
        else {cout<<"NO";}

    }
}