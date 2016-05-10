/****************************************************************************************
 * Author: Ke Wei
 * Project: Date
 * Descrption: practice of class: the projecte performs different ways of calculating
 *             dates
 *          1. adding n dayes from a date to find a new date
 *          2. subtracing n days from a date to find a new date
 *          3. finding out the difference between 2 dates
 * Date Create: 8 Februray 2016
 * Last Date Modified:
 * **************************************************************************************
 * Note:
 *
 * *************************************************************************************/

#include <iostream>
#include "date.h"

using namespace std;

void TestFxns();

int main()
{


    cout << "===========================================" << endl;
    TestFxns();

    cout << "====================END====================" << endl;
    return 0;
}

void TestFxns()
{
    date D1,
         D2(1,1,2016),
         D3(2,28,2015);
    cout << "-------------Accessors------------------" <<endl;
    cout<<"D1 Month: "<<D1.GetMonth()<<endl;
    cout<<"D1 Day: "<<D1.GetDay()<<endl;
    cout<<"D1 Year: "<<D1.GetYear()<<endl;

    cout << "-------------Mutators------------------" <<endl;
    cout<<"D2: "<<D2<<endl;
    D2.SetDay(2);
    D2.SetMonth(2);
    D2.SetYear(2012);
    cout<<"New D2: "<<D2<<endl;

    cout << "-------------ValidDte------------------" <<endl;
//    bool isValide = D1.ValidDate();
//    cout<<"1/1/2016: "<<(isValide? "True":"False")<<endl;
    bool isValide2 = D3.ValidDate();
    cout<<"2/29/2015: "<<(isValide2? "True":"False")<<endl;

    cout << "-------------LeapYear------------------" <<endl;
//    bool isLeap = D1.LeapYear();
//    cout<<"1/1/2016: "<<(isLeap? "True":"False")<<endl;
    bool isLeap2 = D3.LeapYear();
    cout<<"2/29/2015: "<<(isLeap2? "True":"False")<<endl;

    cout << "-------------DaysInMonth------------------" <<endl;
//    int jan = D1.DaysInMonth();
//    cout<<"Jan: "<<jan<<endl;
    int feb = D2.DaysInMonth();
    cout<<"Feb: "<<feb<<endl;

    cout << "-------------Date2DayNumber------------------" <<endl;
//    long int numb1 = D1.Date2DayNumber();
//    cout<<D1<<": "<<numb1<<endl;
    long int numb2 = D2.Date2DayNumber();
    cout<<D2<<": "<<numb2<<endl;

    cout << "-------------Date2DayNumber------------------" <<endl;
    date Date;
    Date = Date.DayNumber2Date(1);
    cout<<"1"<<Date<<endl;

    cout << "-------------Tommorw------------------" <<endl;
    date tomorrow;
    tomorrow = D2.Tomorrow();
    cout<<D2<<endl;
    cout<<"Tomorrow: "<<tomorrow<<endl;

    cout << "-------------|operator +|------------------" <<endl;
    date NewDate;
    NewDate = D2+1;
    cout<<D2<<"+ 1 = "<<NewDate<<endl;

    cout << "-------------|date operator -|------------------" <<endl;
    date NewDate2;
    NewDate2 = D2-1;
    cout<<D2<<"- 1 = "<<NewDate2<<endl;

    cout << "-------------|int operator -|------------------" <<endl;
    int dif = D2-D3;
    cout<<D2<<" - "<<D3<<" = "<<dif<<endl;



}
