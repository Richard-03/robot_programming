# include "matrix.h"
# include <iostream>
using namespace std;

Matrix::Matrix(int nr, int nc){
    if(nr <= 0 || nc <= 0){
        cerr << "Enter positive numbers for matrix dimension" << endl;
        return;
    }
    n = nr;
    m = nc;
    mat = new float* [n];
    for (int i = 0; i < n; i++){
        mat[i] = new float [m];
    }
}

float Matrix::get(int i, int j){
    return mat[i][j];
}

void Matrix::set(int i, int j, float v){
    mat[i][j] = v;
}

Matrix::~Matrix(){
    for(int i = 0; i < n; i++){
        delete [] mat[i];
    }
    delete [] mat;
}

Matrix::Matrix(const Matrix& other){
    n = other.n;
    m = other.m;
    mat = new float* [n];
    for(int i=0; i<n; i++){
        mat[i] = new float[m];
        for(int j=0; j<m; j++){
            mat[i][j] = other.mat[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix returned(*this);
    if (n != other.n || m != other.m){
        cerr << "Dimension mismatch" << endl;
        return returned;
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            returned.mat[i][j] += other.mat[i][j];
        }
    }
    return returned;
}

Matrix Matrix::operator-(const Matrix& other) const{
    Matrix returned(*this);
    if (n != other.n || m != other.m){
        cerr << "Dimension mismatch" << endl;
        return returned;
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            returned.mat[i][j] -= other.mat[i][j];
        }
    }
    return returned;
}    

Matrix Matrix::operator*(const float scalar) const{
    Matrix returned(*this);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            returned.mat[i][j] *= scalar;
        }
    }
    return returned;
}

VecF Matrix::operator*(const VecF& vec) const{
    if (m != vec.size){
        cerr << "Dimension mismatch for matrix multiplication" << endl;
        return vec;
    } 
    // n x size | size x 1 ---> n x 1
    VecF returned = VecF(n);
    for(int i=0; i<n; i++){
        float value = 0;
        for(int j=0; j<m; j++){
            value += mat[i][j] * vec.v[j];
        }
        returned.set(i, value);
    }
    return returned;
}

Matrix Matrix::operator*(const Matrix& other) const{
    if (m != other.n){
        cerr << "Dimension mismatch for matrix multiplication" << endl;
        return *this;
    } 
    Matrix c = Matrix(n, other.m);
    for(int i = 0; i < n; i++){
        // c_ij = sum_{k=0}^cols(A) a_ik * b_kj
        for(int j = 0; j < other.m; j++){
            c.mat[i][j] = 0;
            for(int k=0; k<m; k++){
                c.mat[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }
    return c;
}