//File: Rational Number calculation
//Author: Ke Wei
//Objective: performing +\-\x\/ with 2 rational numbers
//           input and out are using stream functions
//           the arithmetic processes are using friend fucntions using operator to calculate
//Date created: 15 October 2015
//Last dated modifed: 21 Octover 2015

//Note:
/*operator functions
 *format of istream--> istream& operator >>(istream& input, RationalNumber& number) the rationalNumber IS passby reference and give it a new name!!!!
 *when you set the the new rational at calculation, it already checks the error.
 */

#include <iostream>
#include "rationalnumber.h"

using namespace std;

int main()
{
    bool quit = false;
    int choice;
    RationalNumber R1, R2, R3;

    cout<<"R1: "; cin>>R1;
    if (R1.Error())
    {
        cout<<R1.ErrorDescr(R1.Error())<<endl;
        cout<<"Denominator is zero problem"<<endl;
        R1.clear();
        cout<<"R1: ";
        cin>>R1;
    }

    cout<<"R2: "; cin>>R2;
    if (R2.Error())
    {
        cout<<R2.ErrorDescr(R2.Error())<<endl;
        cout<<"Denominator is zero problem"<<endl;
        R2.clear();
        cout<<"R2: ";
        cin>>R2;
    }

    while(!quit)
    {
        cout<<endl<<"================Arithmetic Operations================"<<endl;
        //addition
        R3=R1+ R2;
        if (R3.Error())
        {
            cout<<R3.ErrorDescr(R3.Error())<<endl;
            cout<<"Denominator is zero problem"<<endl;
            R3.clear();
        }
        else
        {
            cout<<"R1+R2="<<R3<<endl;
        }



        //subtration
        R3=R1-R2;
        if (R3.Error())
        {
            cout<<R3.ErrorDescr(R3.Error())<<endl;
            cout<<"Denominator is zero problem"<<endl;
            R3.clear();
        }
        else
        {
            cout<<"R1-R2="<<R3<<endl;
        }

        //multiplication
        R3=R1 * R2;
        if (R3.Error())
        {
            cout<<R3.ErrorDescr(R3.Error())<<endl;
            cout<<"Denominator is zero problem"<<endl;
            R3.clear();
        }
        else
        {
            cout<<"R1xR2="<<R3<<endl;
        }

        //division
        R3 = R1 / R2;
        if (R3.Error())
        {
            cout<<R3.ErrorDescr(R3.Error())<<endl;
            cout<<"Denominator is zero problem"<<endl;
            R3.clear();
        }
        else
        {
            cout<<"R1/R2="<<R3<<endl;
        }

        cout<<"[1]Change R1     [2]Change R2        [0]Quite "<<endl;
        cout<<": "; cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"R1: "; cin>>R1;
                break;
            case 2:
                cout<<"R2: "; cin>>R2;
                break;
            case 0:
                quit = true;
                break;
            default:
                cout<<"["<<choice<<"] is not a valid input"<<endl;

        }
    }
    cout << "================END================" << endl;
    return 0;
}

