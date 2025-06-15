bool ese(const grafo& g, const vector<int>& w){
    bool ok=false;
    for (int i=0;i<g.n();i++){
        int somma_entranti=0;
        int somma_uscenti=0;
        for (int j=0;j<g.n() && j!=i;j++){
            if (g(i,j)){somma_uscenti+=w[j];}
            if (g(j,i)){somma_entranti+=w[j];}
        }
        if (somma_uscenti>=somma_entranti){ok=true;}
        else {return false;}
    }
    return ok;
}