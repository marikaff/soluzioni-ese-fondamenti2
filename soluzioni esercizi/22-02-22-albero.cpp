
bool ese(const alberob<int>& a, vector<int>& cammino, int x){

    if (a.nullo()){
        return false;}
    
    cammino.push_back(a.radice());

    if (a.foglia() && a.radice()==x){
        return true;}
    
    if (ese(a.figlio(SIN),cammino,x) || ese(a.figlio(DES),cammino,x)){
        return true;}
    
    cammino.pop_back();
    return false;
}

