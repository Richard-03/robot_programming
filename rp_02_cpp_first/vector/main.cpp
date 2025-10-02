#include <iostream>
#include "vecF.h"

using namespace std;

// __str__ equivalent
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

// testing
int main(int argc, char* argv[]){
    VecF empty_vector = VecF();
    cout << empty_vector << endl;
    VecF long_vector = VecF(3);
    long_vector.set(0, 1);
    long_vector.set(1, 1.5);
    long_vector.set(2, 2);
    cout << long_vector << endl;
    VecF copied_vector = VecF(long_vector);
    cout << copied_vector << endl;
    VecF v1 = VecF(3);
    v1.set(0, 1);
    v1.set(1, 2);
    v1.set(2, 3);
    cout << v1 << endl;
    VecF v2 = VecF(3);
    v2.set(0, 0);
    v2.set(1, 1);
    v2.set(2, 2);
    cout << "v2 = " << v2 << endl;
    cout << "v2*3 = " << v2*3 << endl;
    cout << "v1+v2 = " << v1 + v2 << endl;
    cout << "v1-v2 = " << v1 - v2 << endl;
    cout << "v1*v2 = "<< v1*v2 << endl;
    return 0;
}
