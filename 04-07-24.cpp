template <class T>
class ArrayWrapper{
    private:
    int size;
    int capacity;
    t* array;

    public:
    ArrayWrapper():size(0),capacity(10){array=new T[capacity]};
 
    ArrayWrapper(const ArrayWrapper<T>& other){this->size=other.size;this->capacity=other.capacity;array=new t[capacity];
        for (int i=0;i<size;i++){this->array[i]=other.array[i];}}

    ~ArrayWrapper(){delete[] array;}

    void resize(){
        T* tmp=new t[capacity*2];
        for (int i=0;i<size;i++){
            tmp[i]=array[i];}
        delete[] array;
        array=tmp;
        capacity*=2;}

    void push_back(const T& v){
        if (size>=capacity){resize();}
        array[size]=v;
        size++;}

    void pop_back(){
        if (size>0){
            size--;}}

    unsigned size(){
        return size;}

    T back(){
        if (size>0){
            return array[size-1];}}

    T& operator[](int i){return array[i];} //posso modificare il valore di array[i]

    T operator[](int i)const{return array[i];} //restituisce una copia dell'elemento all'indice i dell'array, non modificabile

    ArrayWrapper<T>& operator=(const ArrayWrapper& other){
        if (this==other){return *this;}
        delete[] array;
        size=other.size;
        capacity=other.capacity;
        array=new T[capacity];
        for (int i=0;i<size;i++){
            array[i]=other.array[i];
        }
        return *this;
    }



















};