struct soluzione{
    vector<string> lista;
    vector<string> s1;
    vector<string> s2;

    int somma(vector<string> s){
        int sum=0;
        for (int i=0;i<s.size();i++){
            sum+=val(s[i]);
        }
        return sum;}
    
    bool isComplete(){
        return (somma(s1)==somma(s2));}

    void add(vector<string>& s, string x){
        s.push_back(x);}

    void remove(vector<string>& s){
        s.pop_back();}

    bool canAdd(vector<string> s, string x, vector<string> c){
        return (somma(s)+val(x)<=somma(c));}
    
    bool solve(){
        if (isComplete()){return true;}
        for (int i=0;i<lista.size();i++){
            if (canAdd(s1,lista[i],s2)){
                add(s1,lista[i]);
                if (solve()){return true;}
                remove(s1);}
            if (canAdd(s2,lista[i],s1)){
                add(s2,lista[i]);
                if (solve()){return true;}
                remove(s2);}
            
    }
    return false;

}

};