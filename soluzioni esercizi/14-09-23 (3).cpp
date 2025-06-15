#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Esercizio{
    private:
    string descrizione;
    int difficolta;

    public:
    string get_descrizione() const{return descrizione;}
    int get_difficolta() const{return difficolta;}
};

class BancaDati{
    private:
    //uso due mappe, una dove ho id e esercizio, e una per le occorrenze (quante volte è stato gi assegnato l'esercizio),
    //di string, che sarebbe l'id dell'esercizio e poi int
    unordered_map<string, Esercizio> esercizi;
    unordered_map<string, int> assegnati;


    public:
    bool aggiungiEsercizio(string id, Esercizio e){
        for (auto it=esercizi.begin();it!=esercizi.end();it++){
            if (it->first==id){return false;}
        }
        esercizi[id]=e;
        assegnati[id]=0;
        return true;
    }

    vector<Esercizio> creaEsame(int n, int diff_M, int rep_M){
        vector<Esercizio> esame;
        int diff_tot=0;

        for (auto it=esercizi.begin();it!=esercizi.end();it++){
            if (assegnati[it->first]<rep_M && diff_tot+it->second.get_difficolta()<=diff_M){
                esame.push_back(it->second);
                diff_tot+=it->second.get_difficolta();
                assegnati[it->first]++;

                if (esame.size()==n){break;}
            }
        }

        return esame;

        }


    };
