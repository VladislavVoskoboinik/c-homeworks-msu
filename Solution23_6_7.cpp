#include <iostream>
#include<cmath>

using namespace std;

class Vector {
private:
    int capacity;
    int Size;
protected:
    int* Vect;
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



class ComplexNumber{
protected:
    int Re;
    int Im;
public:
    ComplexNumber(int RealPart = 0, int ImaginaryPart = 0){
        Re = RealPart;
        Im = ImaginaryPart;
    }
    
    ComplexNumber operator+(const ComplexNumber& AddComplexNumber) const {
        return ComplexNumber(AddComplexNumber.Re + Re, AddComplexNumber.Im + Im);
    }
    
    ComplexNumber operator-(const ComplexNumber& MinusComplexNumber) const {
        return ComplexNumber(Re - MinusComplexNumber.Re, Im - MinusComplexNumber.Im);
    }
    
    ComplexNumber operator*(const ComplexNumber& MultComplexNumber) const {
        return ComplexNumber((Re * MultComplexNumber.Re - Im*MultComplexNumber.Im), (Re*MultComplexNumber.Im + Im*MultComplexNumber.Re));
    }
    
    ComplexNumber operator/(const ComplexNumber& DivComplexNumber) const {
        return ComplexNumber(
                             (Re*DivComplexNumber.Re + Im*DivComplexNumber.Im)/(DivComplexNumber.Re*DivComplexNumber.Re + DivComplexNumber.Im*DivComplexNumber.Im) , (Im*DivComplexNumber.Re - Re*DivComplexNumber.Im)/(DivComplexNumber.Re*DivComplexNumber.Re + DivComplexNumber.Im*DivComplexNumber.Im)
                             );
    }
    
    ComplexNumber operator+=(const ComplexNumber& AddComplexNumber) {
        Re = AddComplexNumber.Re + Re;
        Im = AddComplexNumber.Im + Im;
        return ComplexNumber(*this);
        
    }
    
    ComplexNumber operator-=(const ComplexNumber& MinusComplexNumber) {
        Re = Re - MinusComplexNumber.Im;
        Im = Im - MinusComplexNumber.Im;
        return ComplexNumber(*this);
    }
    
    ComplexNumber operator=(const ComplexNumber& EqualComplexNumber){
        Re = EqualComplexNumber.Re;
        Im = EqualComplexNumber.Im;
        return ComplexNumber(EqualComplexNumber);
    }
    
    
    
    ~ComplexNumber(){
        Re = 0;
        Im = 0;
    }
    friend ostream& operator << (ostream& os, const ComplexNumber& Number);
    friend istream& operator >> (istream& is, ComplexNumber& Number);
    friend int ModulComplexNumber(ComplexNumber Number);
};

ostream& operator << (ostream& os, const ComplexNumber& Number)
{
    if(Number.Im == 1){
        os << Number.Re << " + i\n";
    }else{
        os << Number.Re << " + " << Number.Im <<  "i\n";
    }
    return os;
}

istream& operator >> (istream& is, ComplexNumber& Number){
    is >> Number.Re >> Number.Im;
    return is;
}

int ModulComplexNumber(ComplexNumber Number){
    return sqrt(Number.Re * Number.Re + Number.Im * Number.Im);
}

class ComplexVector: public Vector{
public:
    friend int ModulComplexNumber(ComplexNumber Number);
    ComplexVector(int N = 0): Vector(2 * N){}
    
    ComplexVector(const ComplexVector& NewComplexVector): Vector ((const int&) NewComplexVector){}
    
    
    int size(){
        return Vector::size() / 2;
    }
    
    ComplexNumber operator [](int idx){
        return ComplexNumber(Vect[idx * 2], Vect[idx * 2 + 1]);
    }
    
    float min = ModulComplexNumber(ComplexNumber(1e9, 1e9));
    ComplexNumber MinComplexNumber = ComplexNumber(1e9, 1e9);
    
    ComplexNumber MinimumModulComplexNumber(){
        for(int idx = 0; idx < Vector::size(); idx += 2){
            if(ModulComplexNumber(ComplexNumber(Vect[idx], Vect[idx + 1])) < min){
                min = ModulComplexNumber(ComplexNumber(Vect[idx], Vect[idx + 1]));
                MinComplexNumber = ComplexNumber(Vect[idx], Vect[idx + 1]);
            }
        }
        return MinComplexNumber;
    }
    friend void operator << (ostream& cout, ComplexVector& CmpVect);
};

void operator << (ostream& cout, ComplexVector& CmpVect){
    for(int i = 0; i < CmpVect.size(); i++){
        cout << CmpVect[i] << " ";
    }
}

class RatioNumber{
protected:
    int Numerator;
    int Denominator;
public:
    RatioNumber(int Num = 0, int Den = 1){
        if(Den == 0) cout << "ZeroDenominator Error!\n";
        Numerator = Num;
        Denominator = Den;
    }
    
    RatioNumber operator+(const RatioNumber& AddRatioNumber) const {
        return RatioNumber(Numerator * AddRatioNumber.Denominator + Denominator * AddRatioNumber.Numerator, Denominator * AddRatioNumber.Denominator);
    }
    
    RatioNumber operator-(const RatioNumber& MinusRatioNumber) const {
        return RatioNumber(Numerator * MinusRatioNumber.Denominator - Denominator * MinusRatioNumber.Numerator, Denominator * MinusRatioNumber.Denominator);
    }
    
    RatioNumber operator*(const RatioNumber& MultRatioNumber) const {
        return RatioNumber(Numerator * MultRatioNumber.Numerator, Denominator * MultRatioNumber.Denominator);
    }
    
    RatioNumber operator/(const RatioNumber& DivRatioNumber) const {
        return RatioNumber(Numerator * DivRatioNumber.Denominator, Denominator * DivRatioNumber.Numerator);
    }
    
    RatioNumber operator+=(const RatioNumber& AddRatioNumber) {
        Numerator = Numerator * AddRatioNumber.Denominator + Denominator * AddRatioNumber.Numerator;
        Denominator = Denominator * AddRatioNumber.Denominator;
        return RatioNumber(*this);
        
    }
    
    RatioNumber operator-=(const RatioNumber& MinusRatioNumber) {
        Numerator = Numerator * MinusRatioNumber.Denominator - Denominator * MinusRatioNumber.Numerator;
        Denominator = Denominator * MinusRatioNumber.Denominator;
        return RatioNumber(*this);
    }
    
    RatioNumber operator=(const RatioNumber& EqualRatioNumber){
        Numerator = EqualRatioNumber.Numerator;
        Denominator = EqualRatioNumber.Denominator;
        return RatioNumber(EqualRatioNumber);
    }
    ~RatioNumber(){
        Numerator = 0;
        Denominator = 1;
    }
    friend ostream& operator << (ostream& os, const RatioNumber& Number);
    friend istream& operator >> (istream& is, RatioNumber& Number);
};

ostream& operator << (ostream& os, const RatioNumber& Number){
    os << Number.Numerator << "/" << Number.Denominator << "\n";
    return os;
}

istream& operator >> (istream& is, RatioNumber& Number){
    is >> Number.Numerator >> Number.Denominator;
    return is;
}


class RatioVector: public Vector{
public:
    RatioVector(int N = 0): Vector(2 * N){}
    
    RatioVector(const RatioVector& NewRatioVector): Vector ((const int&) NewRatioVector){}
    
    
    int size(){
        return Vector::size() / 2;
    }
    
    RatioNumber operator [](int idx){
        return RatioNumber(Vect[idx * 2], Vect[idx * 2 + 1]);
    }
    
    friend void operator << (ostream& cout, RatioVector& RatVect);
};

void operator << (ostream& cout, RatioVector& RatVect){
    for(int i = 0; i < RatVect.size(); i++){
        cout << RatVect[i] << " ";
    }
}

int main(){
    int Vector_size = 0;
    cout << "Enter vector size:\n" << flush;
    cin >> Vector_size;
    cout << "Enter vector size complex numbers\n" << flush;
    ComplexVector a(Vector_size);
    RatioVector b(Vector_size);
    cin >> a;
    cout << "Enter vector size ratio numbers\n" << flush;
    cin >> b;
    cout << a;
    cout << b;
    cout << a.MinimumModulComplexNumber();
    return 0;
}
