#include <iostream>
#include "vecF.h"

using namespace std;

float VecF::get(int i) { 
    return v[i];
}

void  VecF::set(int i,float f) {
    v[i]=f;
}

VecF::VecF() { 
    size=0; 
    v=nullptr;
}

VecF::VecF(int size){
    this->size=size; 
    v=new float[size];
}

VecF::VecF(const VecF& other) {
    size=0; v=0;
    if (! other.size) return;
    size=other.size; v=new float[size];
    for (int i=0; i<size; ++i)
    v[i]=other.v[i];
}

VecF::~VecF() {
    if (size) delete [] v;
}

const float& VecF::at (int idx) const {
    return v[idx];
}

VecF& VecF::operator=(const VecF& other) {
        if (size) delete[] v; size=0; v=0;
        if (! other.size) return *this;
        size=other.size; v=new float[size];
        for (int i=0; i<size; ++i)  
        v[i]=other.v[i];
        return *this;
    }

// addition implementation
VecF VecF::operator+(const VecF& other) {
    // <type> name(*this) <---> combines declaration of a variable and initialization through the constructor
    VecF returned(*this);
    if (size!=other.size) { 
        cerr << "error" << endl;    // 'cerr' is form <iostream>
        return returned;
    }
    for(int i=0; i<size; ++i) 
        returned.v[i]+=other.v[i];
    return returned;
};

// subtraction implementation
VecF VecF::operator-(const VecF& other){
    VecF returned(*this);
    if (size != other.size){    // same as this->size or returned.size
        cerr << "Dimension mismatch" << endl;
        return returned;
    }
    for(int i=0; i < other.size; i++){
        returned.v[i] -= other.v[i];
    }
    return returned;
}

// product per scalar implementation
VecF VecF::operator*(const float s){
    VecF returned(*this);
    for (int i=0; i < size; i++){
        returned.v[i] *= s;
    }
    return returned;
}

// dot produtct implementation
VecF VecF::operator*(const VecF& other){
    VecF returned(*this);
    for(int i=0; i<size; i++){
        returned.v[i] *= other.v[i];
    }
    return returned;
}


