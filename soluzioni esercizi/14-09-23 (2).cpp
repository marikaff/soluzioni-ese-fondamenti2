class Esercizio{
    private:
        string descrizione;
        int difficolta;
    public:
        string getDescrizione(){return Descrizione;}
        int getDifficolta(){return Difficolta;}

};

class BancaDatiEsercizi{
    public:
    vector<pair<string,Esercizio>> eserciziario;

    bool aggiungiEsercizio(string id, Esercizio e){
        for (auto it=eserciziario.begin();it!=eserciziario.end();it++){
            if (eserciziario.first()!=id){
                eserciziario.insert(id,e);}
            else if (eserciziario.first()==id){
                return false;}
                }
        }
        return true;}

    vector<Esercizio> creaEsame(int n, int diff_m, int rep_m) const{
        int somma=0:
        vector <Esercizio> provv;

        while (vector.size()!=n){
            for (auto it=eserciziario.begin();it!=eserciziario.end();it++){
                if (eserciziario.second().getDifficolta()>=diff_m){
                    somma+=eserciziario.second().getDifficolta();
                    provv.push_back(eserciziario.second());
                }}
        }

        if (provv.size()!=n){
            provv.clear();
        }
        return provv;


    }
