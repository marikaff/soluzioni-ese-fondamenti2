#include <iostream>
#include <vector>

using namespace std;

struct soluzione(
    vector<string> s;
    vector<vector<string>> lista;
    int q;

    vector<string> sol;


    bool canAdd(string x){
        bool ok=false;
        //Il codice verifica per ogni lista se tutti i suoi elementi sono presenti in sol. Se troviamo una lista dove ogni elemento è in 
        //sol, restituiamo false. Se nessuna lista è completamente contenuta in sol, alla fine restituiamo true, indicando che la soluzione è valida.
        for (int a=0;a<sol.size();a++){
            if (sol[a]==x){return false;}
        }

        for(int i=0;i<lista.size();i++){
            bool uguali=true;
            for(int j=0;j<lista[i].size();j++){
                bool found=false;
                for(int k=0;k<sol.size();k++){
                    if(sol[k]==lista[i][j]){
                        found=true;
                        break;}
                }
                if(!found){
                    uguali=false;
                    break;
                }
            }
            if(uguali){
                return false;
            }
        ok=true;}

        if (ok && sol.size()>=q){
            return true;}
    }

    bool isComplete(){
        return sol.size()<=q;}

    void remove(){
        if (!sol.empty()){
            sol.pop_back();}}

    
    void add(string x){
        sol.push_back(x);}


    bool solve(){
        if (isComplete()){
            return true;}
        
        for (int i=0;i<s.size();i++){
            if (canAdd(s[i])){
                add(s[i]);
                if (solve()){return true;}
                remove();                
                }
            
        }
        return false; //nessuna soluzione trovata
        
    }

)