#include <vector>
struct soluzione{
    vector<vector<int>> s;
    int k;
    vector<int> h;

    bool isComplete(){
        return h.size==k;}

    void add(int x){
        h.push_back(x);}
    
    void remove(){
        h.pop_back();}
    
    bool canAdd(int x){
        for (int i=0;i<s.size();i++){
            for (int j=0;j<s[i].size() && i!=j;j++){
                for (int k=0;k<h.size();k++){
                    if (h[k]==x){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool solve(){
        if (isComplete()){return true;}
        for (int i=0;i<s.size();i++){
            for (int j=0;j<s[i].size() && i!=j;j++){
                if (canAdd(s[i][j])){
                    add(s[i][j]);
                    if (solve()){return true;}
                    remove();
                }
            }
        }
        return false;
        
        
    
    
    }
    

};