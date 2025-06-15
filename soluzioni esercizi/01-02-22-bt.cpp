struct soluzione{
    grafo g;
    int k1;
    int k2;
    vector<int> u;

    bool isComplete(){
        return (u.size>=k1 && u.size<=k2);}

    void add(int x){u.push_back(x);}
    
    void remove(){u.pop_back();}

    bool canAdd(int x){
        for (int k=0;k<u.size();k++){
            if (u[k]==x){return false;}
            for (int i=0;i<g.n();i++){
                for (int j=0;j<g.n() && i!=j; j++){
                    if (g(i,j)&& (u[k]==i || u[k]==j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool solve(){
        if (isComplete()){return true;}
        for (int i=0;i<g.n();i++){
            if (canAdd(i)){
                add(i);
                if (solve()){return true;}
                remove();
            }
        }
        return false;
    }


};