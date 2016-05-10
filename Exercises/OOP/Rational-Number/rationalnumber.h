#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <iostream>

using namespace std;

class RationalNumber
{
public:
    //constructors
    RationalNumber();
    RationalNumber(int n, int d);
    RationalNumber(int n);

    //Accessor and Mutator
    void setNum(int n);
    void setDen(int d);
    int getNum();
    int getDen();

    //friend functions
    friend RationalNumber operator + (const RationalNumber& R1, const RationalNumber& R2);
    friend RationalNumber operator - (const RationalNumber& R1, const RationalNumber& R2);
    friend RationalNumber operator * (const RationalNumber& R1, const RationalNumber& R2);
    friend RationalNumber operator / (const RationalNumber& R1, const RationalNumber& R2);
    friend ostream& operator << (ostream& out, const RationalNumber& result);
    friend istream& operator >> (istream& input, RationalNumber& number);

    //member functions
    void reduction();


    //error functions
    int Error();
    void clear();
    string ErrorDescr(int e);

private:
    int num;
    int den;
    int CD(int x, int y);
    int error;
};

#endif // RATIONALNUMBER_H
