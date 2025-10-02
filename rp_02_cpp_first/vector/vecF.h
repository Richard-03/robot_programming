struct VecF {
    // attributes
    int size; 
    float* v;

    // member methods/methods
    float get(int i);
    void  set(int i,float f);

    // constructor(s): invoked by 'new'
    VecF();
    VecF(int size);

    // copy constructor
    VecF(const VecF& other);

    // deconstructor: invoked by 'delete'
    ~VecF();

    // operator overload
    VecF& operator=(const VecF& other);

    // EXERCISES FROM HERE

    // access
    // 1. operator[] --> no checks on bounds
    // 2. at method --> makes checks and raise errors

    // const after f(args) means "this method doesn't modify the internal state of 'this' object"
    const float& at (int idx) const;

    // addition 
    VecF operator+(const VecF& other);

    // subtraction 
    VecF operator-(const VecF& other);

    // multiplication by scalar 
    VecF operator*(const float s);

    // dot product
    VecF operator*(const VecF& other);
};