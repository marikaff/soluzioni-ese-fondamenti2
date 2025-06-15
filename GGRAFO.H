#ifndef GRAFO_H_
#define GRAFO_H_

#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Grafo {
private:
    unsigned vn; // numero di nodi
    unsigned vm; // numero di archi
    vector<vector<bool>> archi; // matrice di adiacenza

public:
    // costruttore
    Grafo(unsigned n) : vn(n), vm(0), archi(n, vector<bool>(n, false)) {
        assert(n >= 1);
    }

    // metodi per accedere ai dati
    unsigned n() const { return vn; }
    unsigned m() const { return vm; }

    // metodi per manipolare gli archi
    void inserisciArco(unsigned i, unsigned j) {
        assert(i >= 0 && i < n() && j >= 0 && j < n());
        if (!archi[i][j]) {
            archi[i][j] = true;
            vm++;
        }
    }

    void eliminaArco(unsigned i, unsigned j) {
        assert(i >= 0 && i < n() && j >= 0 && j < n());
        if (archi[i][j]) {
            archi[i][j] = false;
            vm--;
        }
    }

    void svuota() {
        for (unsigned i = 0; i < n(); i++) {
            for (unsigned j = 0; j < n(); j++) {
                archi[i][j] = false;
            }
        }
        vm = 0;
    }

    // metodi per accedere ai vicini
    vector<unsigned> vicinato(unsigned x) const {
        vector<unsigned> nb;
        for (unsigned i = 0; i < n(); i++) {
            if (archi[x][i]) {
                nb.push_back(i);
            }
        }
        return nb;
    }

    unsigned grado(unsigned x) const {
        unsigned g = 0;
        for (unsigned i = 0; i < n(); i++) {
            if (archi[i][x]) {
                g++;
            }
        }
        return g;
    }

    vector<unsigned> gradi() const {
        vector<unsigned> gs(n(), 0);
        for (unsigned i = 0; i < n(); i++) {
            for (unsigned j = 0; j < n(); j++) {
                if (archi[i][j]) {
                    gs[j]++;
                }
            }
        }
        return gs;
    }

    // operatore per accedere agli archi
    bool operator()(unsigned i, unsigned j) const {
        assert(i >= 0 && i < n() && j >= 0 && j < n());
        return archi[i][j];
    }
};

#endif