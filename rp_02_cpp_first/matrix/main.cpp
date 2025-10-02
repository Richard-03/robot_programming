# include <iostream>
# include "matrix.h"

using namespace std;

// NOTA: Un temporaneo non può essere passato a una reference non-const
ostream& operator<<(ostream& os, const Matrix& matrix){
    os << "["; 
    for (int i=0; i<matrix.n; i++){
        os << "[";
        for (int j=0; j<matrix.m; j++){
            os << matrix.mat[i][j];
            if (j != matrix.m-1)
                os << ",";
        }
        os << "]";
    }
    os << "] at address " << &matrix;
    return os;
}
ostream& operator<<(ostream& os, const VecF& v){
    os << "(";
    for (int i = 0; i < v.size; ++i) {
        if (i) 
            os << ", ";
        os << v.at(i);
    }
    os << ")" << " at address " << &v ;
    return os;
}

int main(){
    
    VecF v1 = VecF(3);
    v1.set(0, 1);
    v1.set(1, 2);
    v1.set(2, 3);
    Matrix m1 = Matrix(2, 3);
    m1.set(0,0,1);
    m1.set(0,1,2);
    m1.set(0,2,3);
    m1.set(1,0,1);
    m1.set(1,1,2);
    m1.set(1,2,3);
    Matrix square_1 = Matrix(2,2);
    square_1.set(0,0,1);
    square_1.set(0,1,2);
    square_1.set(1,0,0);
    square_1.set(1,1,1);
    Matrix square_2(square_1);
    Matrix m2 = Matrix(3, 2);
    m2.set(0,0,2);
    m2.set(0,1,4);
    m2.set(1,0,5);
    m2.set(1,1,3);
    m2.set(2,0,4);
    m2.set(2,1,2);

    cout << "square_1 = " << square_1 << endl;
    cout << "square_2 = " << square_2 << endl;
    cout << "addition = " << square_1 + square_2 << endl;
    cout << "subtraction = " << square_1 - square_2 << endl;

    cout << "v1 = " << v1 << endl;
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;

    Matrix double_m1 = m1 * 2;
    cout << "m1 * 2 = " << double_m1 << endl;
    VecF mat_vec_prod = m1 * v1;
    cout << "m1 * v1 = " << mat_vec_prod << endl;
    Matrix mat_mat_vec = m1 * m2;
    cout << "m1 * m2 = " <<m1 * m2 << endl;

    return 0;
}