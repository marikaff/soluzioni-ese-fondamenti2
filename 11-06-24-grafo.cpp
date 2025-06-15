bool funzione(const grafo& g, const vector<unsigned>& x, const vector<unsigned>& y, unsigned z){
    vector<bool> visitati (g.n(),false);

    dfs(x,g,visitati);

    for (int i=0;i<x.size();i++){
        if (!visitati[x[i]]){return false;}
    }

    for (int i=0;i<y.size();i++){
        if (visitati[y[i]]){return false;}

    }
    return true;


}


void dfs(const unsigned& s, const grafo& g, vector<bool>& visitati){
    visitati[s]=true;
    for (int i=0; i<g.n(); i++){
        if (g(s,i) &&  !visitati[i] &&  (i!=s)){
            dfs(i,g,visitati);
        }
    
    }
}