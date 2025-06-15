#include <iostream>
using namespace std;

class stack_con_interessi{
protected:
    double* stack;
    double t;
    int size;

    int capacity;

public:
    stack_con_interessi(double t): t(t), size(0), capacity(3){
       {stack=new double[capacity];}}
    
    stack_con_interessi(const stack_con_interessi & other){this->t=other.t; this->size=other.size; this->capacity=other.capacity;
        stack=new double[capacity];
        for (int i=0;i<size;i++){this->stack[i]=other.stack[i];}}
    
    ~stack_con_interessi(){delete[] stack;}

    void resize(){
        double *tmp=new double[capacity*2];

        for (int i=0;i<size;i++){
            tmp[i]=stack[i];
        }

        delete []stack;
        stack=tmp;

        capacity*=2;
    }

    void pushNew(double x){
        if(size>=capacity)
            resize();
        
        stack[size]=x;
        size++;
    }


    void push(double x){
        double* tmp_stack=new double[capacity];

        size++;
        tmp_stack[size]=x;

        if (size>=capacity){
            capacity*=2;}
        
        delete [] stack;
        stack=tmp_stack;
}

//dopo che mi prendo il primo elemento porto tutti gli elementi avanti di uno
    double pop(){
        double e=stack[0];
        double* tmp_array=new double[capacity];
        size--;
        for (int i=1;i<size;i++){
            tmp_array[i]=stack[i];}
        delete[] stack;
        stack=tmp_array;
        
        return t*e;
    }

    bool operator==(const stack_con_interessi& other) const{
        bool corretto=false;
        for (int i=0;i<size;i++){
            if (stack[i]==other.stack[i]){
                corretto=true;}
            else{return false;}
        }

        if (corretto && t==other.t && size==other.size && capacity==other.capacity){
            return true;}
        return false;
    }

    void stampa(){
        cout<<"Stampa_____"<<endl;
        for(int i=0; i<size; i++){
            cout<<stack[i]<<" ";
        }
        cout<<"_____";

    }



}; 


int main(){
    stack_con_interessi s(1.5);
    s.pushNew(1);
    s.pushNew(2);
    s.pushNew(3);
    
    s.stampa();

    s.pushNew(1);
    s.pushNew(1);
    s.pushNew(1);

    s.stampa();
    

    return 0;
}