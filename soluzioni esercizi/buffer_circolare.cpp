#include <iostream>
#include <stdexcept> // Per std::runtime_error
using namespace std;

class BufferCircolare {
private:
    int* array;
    int size;
    int capacity;

public:
    BufferCircolare() : size(0), capacity(3) {
        array = new int[capacity];}

    ~BufferCircolare() {delete[] array;}

    void resize() {
        int* tmp = new int[capacity*2];
        for (int i = 0; i < size; ++i) {
            tmp[i] = array[i];}
        delete[] array;
        array = tmp;
        capacity*=2;
    }

    int& circolare(int i) {
        return array[i % capacity];
    }


    void aggiungi(int x) {
        if (size >= capacity) {
            resize();
        }
        circolare(size) = x;
        size++;
    }

    void rimuovi(int x) {
        for (int i = 0; i < size; ++i) {
            if (circolare(i) == x) {
                // Shift elements to remove the element
                for (int j = i; j < size - 1; ++j) {
                    circolare(j) = circolare(j + 1);
                }
                --size;
                return; // Exit after removing the first occurrence
            }
        }
    }

    int elemento_corrente() const {
        if (size == 0) {
            return;
        }
        return circolare(0); // Elemento corrente è sempre alla posizione 0
    }

    void avanza() {
        if (size > 0) {
            int primo = circolare(0); // Salva il primo elemento
            for (int i = 0; i < size - 1; ++i) {
                circolare(i) = circolare(i + 1);
            }
            circolare(size - 1) = primo; // Riporta il primo elemento alla fine
        }
    }
};







int main() {
    BufferCircolare bc;
    bc.aggiungi(8);
    bc.aggiungi(4);
    bc.aggiungi(2);

    for (int i = 0; i < 10; ++i) {
        cout << bc.elemento_corrente() << " ";
        bc.avanza();
    }
    cout << endl;

    bc.rimuovi(4);

    for (int i = 0; i < 10; ++i) {
        cout << bc.elemento_corrente() << " ";
        bc.avanza();
    }
    cout << endl;

    return 0;
}
