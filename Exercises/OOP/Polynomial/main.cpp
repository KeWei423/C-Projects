/****************************************************************************************
 * Author: Ke Wei
 * Project: 11.6 Polynomial
 * Descrption: practice of class and dynamic arrays
 *      Using dynamic array to implemnt a polynomial class with plynomial +/-/x
 *      1. using dynmaic array to store coefficients
 *      2. implement a default,copy, parameterized constructor
 *      3. overlaoded operator =
 *      4. destructor
 * Date Create: 8 Februray 2016
 * Last Date Modified:
 * **************************************************************************************
 * Note:
 * 1. Copy constructor:
 * 2. Parameterized constructor
 * 3. overlaoded operator =
 * 4. Destructor
 *
 * *************************************************************************************/

#include <iostream>
#include "poly.h"
using namespace std;

//prototype:


int main()
{
    int degree = 2;
//    int const size = degree +1;
    int values[]={1,1,1};
    cout << "===========================================" << endl;
    cout<<"====test istrea====="<<endl;
    poly test;
    cin>>test;
    cout<<test<<endl;
    cout<<"===================="<<endl;

    int* ptr = values;

    poly a(ptr, degree);
    poly b(a);
    cout<<a<<endl;

    cout<<"a+1="<<a+1<<endl;
    cout<<"1+a="<<1+a<<endl;

    cout<<b<<endl;
    cout<<"a+b: "<<endl;
    cout<<a+b<<endl;

    poly d = a*2;
    cout<<"a: "<<a<<endl;
    cout<<"a*2: "<<d<<endl;

    poly product = a * b;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"proudct: "<<product<<endl;
    cout << "====================END====================" << endl;
    return 0;
}

