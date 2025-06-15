#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void stampa(const vector<string>& s, int k){

    unordered_map<string,int>mappa;

    for (int i=0;i<s.size();i++){
        mappa[s[i]]++;}

    vector<pair<string,int>> v (mappa.begin(),mappa.end());

    auto lambda=[](const auto& a,const auto& b){return a.second>b.second;};

    sort(v.begin(),v.end(),lambda);

    for (int i=0;i<k;i++){
        cout<<v[i].first<<" ";
    }
    cout<<endl;
}

int main(){
    vector<string> ss={"ciao","mondo","suca","ciao"};
    int kk=2;
    stampa(ss,kk);





    return 0;
}