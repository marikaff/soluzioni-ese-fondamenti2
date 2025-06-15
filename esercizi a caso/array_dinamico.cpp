#include <iostream>
using namespace std;

class a{
    private:
        int* arrayy;
        int size;
        int capacity;

    public:
        a():size(0), capacity(3){arrayy=new int[capacity];}
        a(const a & other){this->size=other.size;this->capacity=other.capacity;
            arrayy=new int[capacity]; 
            for(int i=0;i<size;i++){this->arrayy[i]=other.arrayy[i];}}
        ~a(){delete []arrayy;}        

    void resize(){
        int *tmp=new int[capacity*2];
        for (int i=0;i<size;i++){tmp[i]=arrayy[i];}

        delete[] arrayy;
        arrayy=tmp;
        capacity*=2;
    }


    void push(int x){
        if (size>=capacity){
            resize();}
        arrayy[size]=x;
        size++;
    }

    void pop(){
        if (size!=0){
            size--;
        }
    }








};

