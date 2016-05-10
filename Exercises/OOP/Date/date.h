/****************************************************************************************
 * Date.h
 *      Declare varibles and functions in here
 * **************************************************************************************
 * Note:
 *
 * *************************************************************************************/
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;


class date
{
public:
    /*constructor */
    date();
    date(int month, int day, int year);

    /*Accessor*/
    int GetMonth();
    int GetDay();
    int GetYear();

    /*Mutator*/
    void SetMonth(int month);
    void SetDay(int day);
    void SetYear(int year);



    /*basic date calcuation functions*/
    bool ValidDate();   //check for month, day and year
    bool LeapYear();    //check year
    int DaysInMonth();    //get how manys days in that month
    long int Date2DayNumber(); //get the number indicate to that date
    date DayNumber2Date(long daynumber); //get the date refer to that number
    date Tomorrow();

    /*iostream operator functions*/
    //Get date:
//    friend istream& operator >> (istream& out, const date& dmy);

    //print date:
    friend ostream& operator << (ostream& out, const date& dmy);

    /*operator functions */
    friend date operator+ (date& LHS, int RHS);
    friend date operator - (date& LHS, int RHS);
    friend int operator - ( date& LHS, date& D2);


private:
    int dd;
    int mm;
    int yyyy;
};

#endif // DATE_H
