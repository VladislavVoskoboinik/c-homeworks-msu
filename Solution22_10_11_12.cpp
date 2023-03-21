#include <iostream>
#include <cmath>

/*
 Methods:
 -insert
 -erase
 -erase_seq   erase sequence of seq_size elements from index idx
 -erase_seq_between erase sequence of vector elements from idx1 to idx2
 -count return amount of elements el in vector
 -reverse return reversed vector
 -merge  merge vectors a and b like: a + b
 -find return index of element
 */

using namespace std;

class Vector {
private:
    int* Vect;
    int capacity;
    int Size;

public:
    int pow(int base, int power){
        int result = 1;
        for(int i = 0; i < power; i++){
            result *= base;
        }
        return result;
    }
    
    int* Create(int N, int cap){
        int* res = new int[cap];
        if (N > cap) {
            cout << "Capacity error!\n";
        }
        for (int i = 0; i < N; ++i) {
            res[i] = 0;
        }
        return res;
    }
    
    Vector(int N = 1) {
        int i = 1;
        while (N > pow(2, i)) {
            ++i;
        }
        capacity = pow(2, i);
        Size = N;
        Vect = Create(Size, capacity);
    }
    
    Vector(const Vector& NewVector) {
        Size = NewVector.Size;
        capacity = NewVector.capacity;
        Vect = Create(Size, capacity);
        for (int i = 0; i < Size; ++i) {
            Vect[i] = NewVector.Vect[i];
        }
    }

    int size() {
        return Size;
    }
    
    int& operator [] (int idx) {
        if (idx >= Size) {
            cout << "Error!\n";
        }
        return Vect[idx];
    }
    
    int& operator [] (int idx) const {
        if (idx >= Size) {
            cout << "Error!\n";
        }
        return Vect[idx];
    }
    
    Vector& operator = (const Vector& NewVector) {
        Vect = Create(NewVector.Size, NewVector.capacity);
        Size = NewVector.Size;
        capacity = NewVector.capacity;
        for (int i = 0; i < Size; ++i) {
            Vect[i] = NewVector.Vect[i];
        }
        return *this;
    }
    
    Vector& operator += (const Vector& NewVector) {
        for (int i = 0; i < (int)NewVector.Size; ++i) {
            Vect[i] += NewVector.Vect[i];
        }
        return *this;
    }
    
    Vector operator + (const Vector& NewVector) const {
        Vector res(*this);
        res += NewVector;
        return res;
    }

    void insert(int N) {
        Vector res((int)this->Size + 1);
        res[(int)this->Size] = N;
        *this = res;
    }
    
    void erase(int idx) {
        Vector res((int)this->Size - 1);
        for (int i = 0; i < idx; ++i) {
            res[i] = this->Vect[i];
        }
        for (int i = idx; i < res.Size; ++i) {
            res[i] = this->Vect[i + 1];
        }
        *this = res;
        
    }
    
    void erase_seq(int idx, int seq_size) {
        Vector res((int)this->Size - seq_size);
        for (int i = 0; i < idx; ++i) {
            res[i] = this->Vect[i];
        }
        for (int i = idx; i < res.Size; ++i) {
            res[i] = this->Vect[i + seq_size];
        }
        *this = res;
    }
    

    void erase_seq_between(int idx1, int idx2) {
        Vector res((int)this->Size - (idx2 - idx1 - 1) );
        for (int i = 0; i < idx1 + 1; ++i) {
            res[i] = this->Vect[i];
        }
        for (int i = idx1 + 1; i < res.Size; ++i) {
            res[i] = this->Vect[i - 1 + idx2 - idx1];
        }
        *this = res;
    }

    int count(int N) {
        int count = 0;
        for(int i = 0; i < this->Size; ++i){
            if (this->Vect[i] == N) {
                ++count;
            }
        }
        return count;
    }
    
    void merge(const Vector& AddVector) {
        Vector res((int)this->Size + (int)AddVector.Size);
        for (int i = 0; i < this->Size; ++i) {
            res[i] = this->Vect[i];
        }
        for (int i = 0; i < AddVector.Size; ++i) {
            res[i + (int)this->Size] = AddVector[i];
        }
        *this = res;
    }
    
    int find(int N) {
        for (int i = 0; i < this->Size; ++i) {
            if (this->Vect[i] == N) {
                return i;
            }
        }
        return -1;
    }
    
    void reverse() {
        Vector res(*this);
        for (int i = 0; i < res.Size; ++i) {
            res[i] = this->Vect[res.Size - 1 - i];
        }
        *this = res;
    }
    
    
    ~Vector() {
        delete Vect;
    }
    
    friend ostream& operator<<(ostream& os, const Vector& vector);
    friend istream& operator>>(istream& is, const Vector& vector);
};


//Operator overload
ostream& operator<<(ostream& os, const Vector& vector) {
    if (vector.Size == 1) {
        return os << vector[0];
    }
    if (vector.Size == 0) {
        return os << "None.  Vector is empty";
    }
    for (int i = 0; i < (int)vector.Size; ++i) {
        if (i == 0) {
            os<< vector.Vect[i] << " ";
            continue;
        }
        if (i == ((int)vector.Size - 1)) {
            os << vector.Vect[i];
            continue;
        }
        os << vector.Vect[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, const Vector& vector) {
    for (int i = 0; i < vector.Size; ++i) {
        is >> vector[i];
    }
    return is;
}

int main() {
    Vector a(5);
    Vector b(6);
    
    cin >> a >> b;
    a.reverse();
    a.merge(b);
    cout << a;
}
