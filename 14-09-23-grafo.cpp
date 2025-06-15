#include <iostream>
#include <vector>
#include <queue>
#include "Grafo.h"
using namespace std;
vector<int> bfs(const unsigned s, const Grafo& g){

    vector<bool> visitati (g.n(),false);
    vector<int> p (g.n(),-1);
    queue<int> q;

    q.push(s);
    visitati[s]=true;
    p[s]=s;

    while (!q.empty()){
        int u=q.front();
        q.pop();

        for (int v=0;v<g.n();v++){
            if (g(u,v) && u!=v && !visitati[v]){
                visitati[v]=true;
                p[v]=u;
                q.push(v);
            }
        }
    }
    return p;
}


vector<int> ese(const Grafo& g, int u, int v){

    vector<int> dist_u=bfs(u,g);
    vector<int> dist_v=bfs(v,g);

    vector<int> tot;

    for (int i=0;i<dist_u.size();i++){
        for (int j=0;j<dist_v.size();j++){
            if (i!=j && dist_u[i]==dist_v[j]){
                tot.push_back(dist_u[i]);
            }
        }
    }
    return tot;
}



int main() {
    Grafo g(6); // crea un grafo con 6 nodi

    // aggiungi archi al grafo
    g(0, 1, true);
    g(0, 2, true);
    g(1, 3, true);
    g(2, 3, true);
    g(3, 4, true);
    g(3, 5, true);

    int u = 0; // nodo di partenza
    int v = 3; // nodo di arrivo

    vector<int> result = ese(g, u, v);

    cout << "Nodi che rispettano la condizione: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}