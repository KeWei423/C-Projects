#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "addentry.h"
using namespace std;

class Vector
{
public:
    Vector();
    Vector(int size);
    Vector(string *ptr, int size);

    //===========
    // the big 3
    //===========
    Vector(const Vector& source); //copy constructor
    ~Vector();
    Vector& operator = (const Vector& RHS);

    void Copy(string* source, string* dest, int length);
    void Print();
//    friend ostream& operator<<(ostream& out, const Vector& Entry);

    void AddEntry(string item);
    void DeleteEntry(string item);

private:
    int length;
    string *str;

};

#endif // VECTOR_H
