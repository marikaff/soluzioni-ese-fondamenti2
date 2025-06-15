using namespace std;

string ese(const albero_b<string>& a){
     string ris;

    if (a.nullo()){
        ris="";}
    
    if (a.foglia()){
        ris=a.radice();}

    else{
        string sx=ese(a.figlio(SIN));
        string dx=ese(a.figlio(DES));
        ris="("+sx+a.radice()+dx+")";}
    
    return ris;
}