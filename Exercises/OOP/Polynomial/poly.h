#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;

const int DEFAULT_SIZE = 1;

class poly
{
public:
    /*constructor*/
    poly();
    poly(int *coefficient, int degree);
    //===========
    // the big 3
    //===========
    poly(const poly& SourcePoly);
    /*destructor*/
    ~poly();
    /*assignment operator*/
    poly& operator = (const poly& RHS);



    /*operator functions*/
    int *Allocate(int size);
    void Copy(int* source, int* dest, int length);
    void Init(int* ptr, int size);


    friend istream& operator >> (istream& input, poly& inputThis);
    friend ostream& operator << (ostream& output, const poly& printMe);
    friend bool rhsIsBigger(const poly& LHS, const poly& RHS);

    friend poly operator + (const poly& LHS, int rhs);
    friend poly operator + (int lhs, const poly& RHS);
    friend poly operator + (const poly& LHS, const poly& RHS);

    friend poly operator - (const poly& LHS, int rhs);
    friend poly operator - (int lhs, const poly& RHS);
    friend poly operator - (const poly& LHS, const poly& RHS);

    friend poly operator * (const poly& LHS, int rhs);
    friend poly operator * (int lhs, const poly& RHS);
    friend poly operator * (const poly& LHS, const poly& RHS);


private:
    int *coef;
    int size;
};

#endif // POLY_H
