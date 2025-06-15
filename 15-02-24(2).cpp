#include <iostream>
using namespace std;

class stack{
    private:
    double* pila;
    double t;
    int size;
    int capacity;

    public:
    stack(double t):t(t),size(0),capacity(3){pila=new double[capacity];};
    stack(const stack& other){this->t=other.t;
        this->capacity=other.capacity;this->size=other.size;
        pila=new double[capacity]; 
        for (int i=0;i<size;i++){
            this->pila[i]=other.pila[i];
        }}
    ~stack(){delete[] pila;}

    void resize(){
        double* tmp=new double[capacity*2];
        for (int i=0;i<size;i++){
            tmp[i]=pila[i];
        }
        delete[] pila;
        pila=tmp;
        capacity*=2;    
    }

    void push(double x){
        if (size>=capacity){resize();}
        pila[size]=x;
        size++;
    }

    double pop(){
        double x=pila[size-1];
        size--;
        return x*t;
    }

    stack& operator=(const stack& other){
        if (this==&other){return *this;}
        delete[] pila;
        t=other.t;
        size=other.size;
        capacity=other.capacity;
        pila=new double[capacity];
        for (int i=0;i<size;i++){
            pila[i]=other.pila[i];
        }
        return *this;
    }




};

int main(){
    stack s(1.5);
    s.push(1);
    s.push(3);
    s.push(5);
    s.pop();



}