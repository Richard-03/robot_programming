# include "../vector/vecF.h"

struct Matrix{
    // attributes
    int n;
    int m;
    float** mat;
    
    // getter and setter
    float get(int i, int j);
    void set(int i, int j, float v);

    // constructor;
    Matrix(int nr, int nc);   // n x m

    // copy constructor
    Matrix(const Matrix& other);

    // deconstructor
    ~Matrix();

    // const wherever internal state doesn't change

    // addition
    Matrix operator+(const Matrix& other) const;

    // subraction
    Matrix operator-(const Matrix& other) const;
    
    // products
    Matrix operator*(const float scalar) const;
    VecF operator*(const VecF& vec) const;
    Matrix operator*(const Matrix& other) const;

};