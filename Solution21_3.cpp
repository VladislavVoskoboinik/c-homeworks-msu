//
//  main.cpp
//  Seminar1C++
//  Simple 2x2 matrix Class


#include <iostream>

using namespace std;


class matrix{
    private:
        int rows = 2;
        int colomns = 2;
    public:
        int matrixElement_1 = 1;
        int matrixElement_2 = 0;
        int matrixElement_3 = 0;
        int matrixElement_4 = 1;
    
        matrix(int matrixElement_1,int matrixElement_2,int matrixElement_3,int matrixElement_4){
            this->matrixElement_1 = matrixElement_1;
            this->matrixElement_2 = matrixElement_2;
            this->matrixElement_3 = matrixElement_3;
            this->matrixElement_4 = matrixElement_4;
        }
        matrix(){
            
        }
        matrix operator = (matrix mx){
            matrixElement_1 = mx.matrixElement_1;
            matrixElement_2 = mx.matrixElement_2;
            matrixElement_3 = mx.matrixElement_3;
            matrixElement_4 = mx.matrixElement_4;
            return(*this);
        }
    
        matrix operator + (matrix mx){
            matrix newMatrix;
            newMatrix.matrixElement_1 = matrixElement_1 + mx.matrixElement_1;
            newMatrix.matrixElement_2 = matrixElement_2 + mx.matrixElement_2;
            newMatrix.matrixElement_3 = matrixElement_3 + mx.matrixElement_3;
            newMatrix.matrixElement_4 = matrixElement_4 + mx.matrixElement_4;
            return newMatrix;
        }
    
        matrix operator - (matrix mx){
            matrix newMatrix;
            newMatrix.matrixElement_1 = matrixElement_1 - mx.matrixElement_1;
            newMatrix.matrixElement_2 = matrixElement_2 - mx.matrixElement_2;
            newMatrix.matrixElement_3 = matrixElement_3 - mx.matrixElement_3;
            newMatrix.matrixElement_4 = matrixElement_4 - mx.matrixElement_4;
            return newMatrix;
        }
    
        matrix operator += (matrix mx){
            matrixElement_1 += mx.matrixElement_1;
            matrixElement_2 += mx.matrixElement_2;
            matrixElement_3 += mx.matrixElement_3;
            matrixElement_4 += mx.matrixElement_4;
            return(*this);
        }
    
        matrix operator -= (matrix mx){
            matrixElement_1 -= mx.matrixElement_1;
            matrixElement_2 -= mx.matrixElement_2;
            matrixElement_3 -= mx.matrixElement_3;
            matrixElement_4 -= mx.matrixElement_4;
            return(*this);
        }
    
        matrix operator * (matrix mx){
            matrix newMatrix;
            newMatrix.matrixElement_1 = matrixElement_1 * mx.matrixElement_1 + matrixElement_2 * mx.matrixElement_3;
            newMatrix.matrixElement_2 = matrixElement_1 * mx.matrixElement_2 + matrixElement_2 * mx.matrixElement_4;
            newMatrix.matrixElement_3 = matrixElement_3 * mx.matrixElement_1 + matrixElement_4 * mx.matrixElement_3;
            newMatrix.matrixElement_4 = matrixElement_3 * mx.matrixElement_2 + matrixElement_4 * mx.matrixElement_4;
            return(newMatrix);
        }
    
        ~matrix(){
        }
};

ostream& operator << (ostream& os, matrix& mx){
    os << mx.matrixElement_1 << " " << mx.matrixElement_2 << "\n" << mx.matrixElement_3 << " " << mx.matrixElement_4 << "\n";
    return os;
}

istream& operator >> (istream& is, matrix& mx){
    is >> mx.matrixElement_1 >> mx.matrixElement_2 >> mx.matrixElement_3 >> mx.matrixElement_4;
    return is;
}

int main(int argc, const char * argv[]) {
    matrix M, N, Res;
    char op;
    cout << "Enter matrix M elements:\n" << flush;
    cin >> M;
    cout << "Enter matrix N elements:\n" << flush;
    cin >> N;
    cout << "Enter operator sign:" << flush;
    cin >> op;
    
    switch(op){
        case '+':
            Res = M + N;
            break;
        case '-':
            Res = M - N;
            break;
        case '*':
            Res = M * N;
            break;
        default:
            cout << "Calculation error :(\n";
            break;
    }
    cout << "Result is:\n" << M << op << "\n" << N << "=\n" << Res;

    return 0;
}
