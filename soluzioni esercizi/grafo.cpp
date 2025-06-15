#include "grafo.h"

//G.n() da il numero di nodi

unsigned contaNodiNonRaggiunti(const Grafo& G, unsigned u) {
    unsigned cont = 0;
    for (unsigned i = 0; i < G.n(); ++i) {
        if (i != u && !G(i, u)) {
            cont++;
        }
    }
    return cont;
}

unsigned esercizio3(const Grafo& G) {
    unsigned nodoMaxNonRaggiunto = 0; //memorizza il nodo con il massimo numero di nodi non raggiunti
    unsigned maxNodiNonRaggiunti = contaNodiNonRaggiunti(G, 0); //memorizza tale numero.

    for (unsigned i = 0; i < G.n(); ++i) {
        unsigned nodiNonRaggiunti = contaNodiNonRaggiunti(G, i);
        if (nodiNonRaggiunti > maxNodiNonRaggiunti || 
            (nodiNonRaggiunti == maxNodiNonRaggiunti && i < nodoMaxNonRaggiunto)) {
            nodoMaxNonRaggiunto = i;
            maxNodiNonRaggiunti = nodiNonRaggiunti;
        }
    }

    return nodoMaxNonRaggiunto;
}
