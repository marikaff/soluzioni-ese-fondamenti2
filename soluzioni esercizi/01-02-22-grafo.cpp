int ese(const grafo& g){
    vector<int> non_raggiunti (g.n(),0);

    for (int i=0;i<g.n();i++){
        vector<bool> visitati (g.n(),false);

        dfs(i,g,visitati);

        for (int j=0;j<g.n();j++){
            if (visitati[j]==false){
                non_raggiunti[i]++;
            }}}

    int nodo_min=non_raggiunti[0];
    int num_max=0;

    for (int i=0;i<g.n();i++){
        if (non_raggiunti[i]>num_max){
            nodo_min=i;
            num_max=non_raggiunti[i];
        }
    }
    return nodo_min;
}

void dfs(int x, const grafo& g, vector<bool>& visitati){
    visitati[x]=true;
    for (int i=0;i<g.n();i++){
        if (i!=x && !visitati[i] && g(x,i)){
            dfs(i,g,visitati);
        }
    }
}