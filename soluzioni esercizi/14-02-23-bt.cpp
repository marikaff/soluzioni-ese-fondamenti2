struct soluzione{
    Grafo g;
    int k;
    int n;
    vector<int> w;
    vector<int> gradi;

    void gradi_nodi(){
        for (int i=0;i<n;i++){
            int somma=0;
            for (int j=0;j<n && i!=j;j++){
                if (g(i,j)){somma++;}
            }
            gradi[i]=somma;}
    }
    bool isComplete(){
        int somma=0;
        for (int i=0;i<w.size();i++){
            somma+=gradi[w[i]];}
        return (w.size()==k && somma<=n);
    }

    void remove(){w.pop_back();}
    void add(int x){w.push_back(x);}

    bool canAdd(int x){
        for (int i=0;i<w.size();i++){
            if (g(x,j)){return false;}}
        return true;
    }

    bool solve(){
        if (isComplete()){return true;}

        for (int i=0;i<n;i++){
            if (canAdd(i)){
                add(i);
                if (solve()){return true;}
                remove();
            }
        }
        return false;
    }
  


}