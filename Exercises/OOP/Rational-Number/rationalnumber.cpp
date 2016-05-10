#include "rationalnumber.h"
#include <iostream>

using namespace std;

RationalNumber::RationalNumber():num(0), den(1),error(0)
{
    //Intend to leave blank
}


RationalNumber::RationalNumber(int n, int d):num(n),den(d),error(0)
{
    if (den == 0)
    {
        error =1;
        num=0;
        den=1;
    }
}


RationalNumber::RationalNumber(int n):num(n),den(1),error(0)
{
    //No error check is needed for this construction becasue denominator is 1 always
}


int RationalNumber::CD(int x, int y)
{
    int t;
    while(y!=0)
    {
        t = y;
        y = x % y;
        x = t;
    }
    return x;
}

void RationalNumber::setNum(int n)
{
    num = n;
}


void RationalNumber::setDen(int d)
{

    den = d;
}


int RationalNumber::getNum()
{
    return num;
}


int RationalNumber::getDen()
{
    return den;
}


RationalNumber operator + (const RationalNumber& R1, const RationalNumber& R2)
{
    int NN = (R1.num * R2.den) + (R1.den * R2.num);
    int DD = R1.den * R2.den;
    RationalNumber R3 = RationalNumber(NN,DD);
    R3.reduction();
    return R3;
}

RationalNumber operator - (const RationalNumber& R1, const RationalNumber& R2)
{
    int NN = (R1.num * R2.den) - (R2.num * R1.den);
    int DD = R1.den * R2.den;
    RationalNumber R3 = RationalNumber(NN, DD);
    R3.reduction();
    return R3;
}

RationalNumber operator * (const RationalNumber& R1, const RationalNumber& R2)
{
    int NN = R1.num * R2.num;
    int DD = R1.den * R2.den;
    RationalNumber R3 = RationalNumber(NN, DD);
    R3.reduction();
    return R3;
}


RationalNumber operator / (const RationalNumber& R1, const RationalNumber& R2)
{
    int NN = R1.num * R2.den;
    int DD = R1.den * R2.num;
    RationalNumber R3 = RationalNumber (NN, DD);
    R3.reduction();
    return R3;
}


void RationalNumber::reduction()
{
    int temp = CD(num,den);
    num = num /temp;
    den = den /temp;
}


ostream& operator<<(ostream& out, const RationalNumber& RationalNumber)
{
    out<<RationalNumber.num<<"/"<<RationalNumber.den;
//    out<<RationalNumber.num<<"/"<<RationalNumber.den;
    return out;
}

istream& operator >>(istream& input, RationalNumber& number)
{
    char slash;
    input>>number.num;
    cin.get(slash);
    if(slash != '/')
    {
        cin.unget();
        number.den=1;
    }
    else
    {
        input>>number.den;
    }

    if(number.den ==0)
    {
        number.error=1;
        number.den=1;
        number.num=0;

    }
    return input;
}

int RationalNumber::Error()
{
    return error;
}

void RationalNumber::clear()
{
    error = 0;
}

string RationalNumber::ErrorDescr(int e)
{
    switch(e)
    {
        case 1:
            return "Diving zero problem!";
        default:
            return "Unknown Error";
    }
}
