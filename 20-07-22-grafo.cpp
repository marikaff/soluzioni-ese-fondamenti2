int ese(const  grafo& g){
    int ris;
    for (int i=0;i<g.n();i++){
        int somma=0;
        int media=0;
        int pot_corr=-1, max_pot=-1;
        for (int j=0;j<g.n() && j!=i;j++){
            if (g(i,j)){
                somma+=g.pot(j);
                media++;}
        }

        if (g.pot(i)>somma/media){
            ris=i;
            pot_corr=g.pot(i);}
        if (pot_corr>max_pot){
            max_pot=pot_corr;
            ris=i;}
    }
    return ris;




}