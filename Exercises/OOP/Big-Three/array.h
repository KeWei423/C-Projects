#ifndef ARRAY_H
#define ARRAY_H


class Array
{
public:
    Array();
    Array(int* ptr, int n);

    //==========
    //the big 3
    //==========
    Array(const Array& a);
    ~Array();
    Array& operator = (const Array& a);

    void Copy(int* source, int* dest, int length);
    void Print();

private:
    int size;
    int *vals;
};

#endif // ARRAY_H
