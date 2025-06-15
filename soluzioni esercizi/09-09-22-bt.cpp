#include <iostream>
#include <vector>
using namespace std;

struct transazione{
    vector<string> v;
    vector<vector<string>> t;
    int k;

    vector<string> sol;

    bool isComplete(vector<string> sol){
        return (sol.size()>=k);
    }

    void add(string x){
        sol.push_back(x);
    }

    void remove(){
        sol.pop_back();
    }

//RIVEDERE QUESTA FUNZIONE
    bool canAdd(string x){ 
        for (int i=0;i<sol.size();i++){
            bool not_ok=false;
            for (int j=0;j<t.size();j++){
                for (int k=0;k<t[j].size();k++){
                    if (sol[i]==t[j][k]){
                        not_ok=true;}
                }
                if (not_ok){break;}

            }
        }
        //return not_ok;
    }

    bool solve(){
        if (isComplete(sol)){
            return true;}
        
        for (int i=0;i<v.size();i++){
            if (canAdd(v[i])){
                add(v[i]);
                if (solve()){return true;}
                remove();
            }
        }
        return false;


    }

};