#include <iostream>
using namespace std;


//ESERCIZIO 1

class ese1{
    void func(char& a, char b){
        char c = a;
        a = b;
        b = c;}


    int main()
    {
        char* nome = new char[3]{'m','a','r'};

        

        cout << *(nome + 2) << endl;

   
        


            return 0;
        }
};

//ESERCIZIO 2

