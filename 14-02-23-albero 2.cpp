// scrivere una funzione che da true se esiste almeno un nodo foglia x, tale che la somma dei valori 
// infomartivi dei nodi sul percorso dalla radice a x è pari a 0, false altrimenti

bool ese(const AlberoB<int> & a, vector<int>& percorso){

    if (a.nullo()){
        return false;}

    percorso.push_back(a.radice);


    if (a.foglia() && sum(percorso)){
        return true;}

    if (ese(a.figlio(SIN), percorso) || ese(a.figlio(DES), percorso)){
        return true;
    }


    percorso.pop_back(a.radice());
    return false;


}

bool sum(vector<int>& perc){
    ese(const AlberoB<int>& a, perc);
    int somma=0;

    for (int i=0;i<perc.size();i++){
        somma+=perc[i];}
    
    return(somma==0)
}