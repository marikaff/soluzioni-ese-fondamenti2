#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace::std;


class partita{
private:
    string squadra_casa;
    string squadra_ospite;
    int goal_casa;
    int goal_ospite;
public:
//COSTRUTTORE
    partita(string squadra_casa, string squadra_ospite, int goal_casa, int goal_ospite):squadra_casa(squadra_casa),squadra_ospite(squadra_ospite),goal_casa(goal_casa), goal_ospite(goal_ospite){}
//GET
    string get_squadra_casa(){return squadra_casa;}
    string get_squadra_ospite(){return squadra_ospite;}
    int get_goal_casa(){return goal_casa;}
    int get_goal_ospite(){return goal_ospite;}
//SET
    void set_squadra_casa(string squadra_casa){this->squadra_casa=squadra_casa;}
    void set_squadra_ospite(string squadra_ospite){this->squadra_ospite=squadra_ospite;}
    void set_goal_casa(int goal_casa){this->goal_casa=goal_casa;}
    void set_goal_ospite(int goal_ospite){this->goal_ospite=goal_ospite;}
};

class gestore_partite{
private:
    list<partita*> partite;
public:
    void aggiungi_partita(string squadra_casa, string squadra_ospite, int goal_casa, int goal_ospite){
        partita* nuova_partita=new partita(squadra_casa,squadra_ospite,goal_casa,goal_ospite);
        partite.push_back(nuova_partita);}
    
    string get_squadra_piu_forte() const{
        unordered_map <string,int> mappa;
        
        for (auto it=partite.begin();it!=partite.end();it++){
            if ((*it)->get_goal_casa()>(*it)->get_goal_ospite()){
                mappa[(*it)->get_squadra_casa()]++;}
            if ((*it)->get_goal_casa()<(*it)->get_goal_casa()){
                mappa[(*it)->get_squadra_ospite()]++;}}
        
        int massimo=0;
        string squadra_forte;
        for (auto it=mappa.begin();it!=mappa.end();it++){
            if ((*it).second>massimo){
                massimo=(*it).second;
                squadra_forte=(*it).first;}}
        return squadra_forte;}
    
    double media_goal() const{
        int somma=0;
        int cont=0;
        
        for (auto it=partite.begin();it!=partite.end();it++){
            somma+=(*it)->get_goal_casa();
            somma+=(*it)->get_goal_ospite();
            cont++;}
        return somma/cont;}
    
    gestore_partite(const gestore_partite& other){
        partite=other.partite;}
    
};
