#include "albero.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool esercizio3(const string& s, const AlberoB<char>& a, string& controllo){
    if (a.nullo()){
        return false;}
    
    controllo+=a.radice();
    
    if (esercizio3(s,a.figlio(SIN),controllo) || esercizio3(s, a.figlio(DES),controllo)){
        return true;}
    
    if (a.foglia() && controllo==s){
        return true;}
    
    controllo.pop_back();
    return false;}

bool ritorna(const string& s, const AlberoB<char>& a){
    string controlla;
    esercizio3(s, a, controlla);
    if (controlla==s){return true;}
    else {return false;}
}

//
//bool esercizio3(const string& s, const AlberoB<char>& t, string& stringa){
//    if (t.nullo()){
//        return false;}
//    
//    stringa+=t.radice();
//    
//    if (t.foglia() && stringa==s){
//        return true;}
//
//    if (esercizio3(s,t.figlio(SIN),stringa) || esercizio3(s,t.figlio(DES),stringa)){
//        return true;}
//    
//    stringa.pop_back();
//    return false;
//}
//
//bool ritorna(const string& s, const AlberoB<char>&t ){
//    string stringa;
//    if (esercizio3(s, t, stringa)){
//        return true;}
//    else {return false;}
//}
