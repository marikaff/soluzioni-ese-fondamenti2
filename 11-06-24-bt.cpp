#include <iostream>
#include <vector>
using namespace std;

struct pallamano{
    vector<unsigned> abilities;
    int k;
    vector<int> squadra1;
    vector<int> squadra2;
    vector<pair<int,bool>> mappa;

    for (int i=0;i<abilities.size();i++){
        mappa.insert({abilities[i],false});}
    
    int sum(const vector<int>& v){
        int somma=0;
        for (int i=0;i<v.size();i++){
            somma+=v[i];}
        return somma;}
    
    bool isComplete(){
        for (int i=0;i<mappa.size();i++){
            if (mappa[i].second==false){
                return false;}}
        if ((sum(squadra1)+sum(squadra2)<=k) || (sum(squadra2)+sum(squadra1)<=k)){
            return true;}
        
        return false;}
    
    void add(vector<int> s, int x){
        s.push_back(x);
        for (int i=0;i<mappa.size();i++){
            if (mappa[i].first==x){
                mappa[i].second=true;}}
        
        }
    
    void remove(vector<int> s){
        int x=s.back();
        s.pop_back();

        for (int i=0;i<mappa.size();i++){
            if (mappa[i].first==x){
                mappa[i].second=false;}}}

    bool solve(){
        if (isComplete()){
            return true;}
        
        for (int i=0;i<mappa.size();i++){
            if (mappa[i].second==false){
                int x=mappa[i].first;

                add(squadra1,x);
                if (solve()){return true;}
                remove(squadra1);

                add(squadra2,x);
                if (solve()){return true;}
                remove(squadra2);

            }
        }

        return false;
    }

};