#include "array.h"
#include <iostream>
using namespace std;

Array::Array(): size(1), vals(NULL)
{
    cout<<"Fire default constructor"<<endl;
}


Array::Array(int* ptr, int n)
{
    cout<<"Fire parameterized constructor"<<endl;
    size = n;
    vals = new int[size];
    Copy(ptr, vals, size);
}


Array::Array(const Array& a)
{
    cout<<"Fire copy constructor"<<endl;
    size = a.size;
    vals = new int [size];
    Copy(a.vals, vals, size);
}


Array::~Array()
{
    cout<<"Fire Destructor"<<endl;
    delete []vals;
    vals = NULL;
}


Array& Array:: operator = (const Array& a)
{
    cout<<"Fire assignment operator"<<endl;
    if(& a != this)
    {
        delete [] vals;
        size = a.size;
        vals = new int [a.size];
        Copy(a.vals, vals, size);
    }
    return *this;
}


void Array::Copy(int *source, int *dest, int length)
{
    cout<<"Fire Copy"<<endl;
    int* sourceWalker = source;
    for(int i=0; i<length; i++)
    {
        *dest = *sourceWalker;
        sourceWalker++;
        dest++;
    }
}

void Array::Print()
{
    int* valWalker = vals;
    for(int i=0; i<size; i++)
    {
        cout<<"|"<<*valWalker<<"|";
        valWalker++;
    }
}
