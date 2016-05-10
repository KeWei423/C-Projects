#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    int const SIZE = 4;
    int values[SIZE]={0,1,2,3};
    cout << "==================================" << endl;
    int* ptr = values;
    Array a1(ptr, SIZE);
    cout<<"a1: ";
    a1.Print();
    cout<<endl;
    cout<<endl;

    Array a2(a1);
    cout<<"a2(a1): ";
    a2.Print();
    cout<<endl;
    cout<<endl;

    Array a3 = a1;
    cout<<"a3 = a1: ";
    a3.Print();
    cout<<endl;
    cout<<endl;

    Array a4;
    a4 = a1;
    cout<<"a4 = a1: ";
    a4.Print();
    cout<<endl;


    cout << "==================================" << endl;
    return 0;
}

