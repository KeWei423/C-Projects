/****************************************************************************************
 * Date.h
 *      Declare varibles and functions in here
 * **************************************************************************************
 * Note:
 *
 * *************************************************************************************/
#include "date.h"
#include <math.h>

/*constructor */
date::date(): dd(1), mm(1), yyyy(2016)
{
    //the default date is 01/01/2016
}

date::date(int month, int day, int year)
{
    mm = month;
    dd = day;
    yyyy=year;
    //check error

}



/*Accessor*/
int date:: GetMonth()
{
    return mm;
}

int date:: GetDay()
{
    return dd;
}

int date:: GetYear()
{
    return yyyy;
}



/*Mutator*/
void date::SetMonth(int month)
{
    mm = month;
}

void date::SetDay(int day)
{
    dd = day;
}

void date::SetYear(int year)
{
    yyyy = year;
}



/*basic date calcuation functions*/
//check for month, day and year
bool date::ValidDate()
//retur true if the date is valid
{
    if ((yyyy <1582) || (yyyy > 3000))
        {
            return false;
        }
        else if ((mm < 1) || (mm > 12))
        {
            return false;
        }
        else if ((dd <1) || (dd > DaysInMonth()))
        {
            return false;
        }
        else
        {
            return true;
        }

}


//check year
bool date::LeapYear()
//if is leap year return true;
{
    if ((yyyy % 4 == 0) && (yyyy % 100 ) != 0)
        {
            return true;
        }
        else if (yyyy % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

}


//get how manys days in that month
int date::DaysInMonth()
//return the days in a month
{
    int days;
    switch(mm)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days=30;
            break;
        case 2:
            if (LeapYear() == true)      //check for leap year.
            {
                days=29;
            }
            else
            {
                days=28;
            }
            break;
    }
    return days;
}


//get the number of days has passed since the beginning of the year
long int date::Date2DayNumber()
//return a number that indicate the date in the year
{
    long int sum=0,
             dayNumber;
    int month = mm;

    for (mm=1; mm<month; mm++)
    {
        sum=sum+DaysInMonth();
    }

    dayNumber=sum+dd;
    return dayNumber;
}

//get the date refer to that number
date date::DayNumber2Date(long int daynumber)
//return a date that refer to that number in the year
{
//    cout<<"year: "<<yyyy<<endl;
    mm=1;
    while (daynumber > DaysInMonth())
    {
        daynumber = daynumber - DaysInMonth();
        mm += 1;
        if (mm >12)
        {
            mm=1;
            yyyy +=1;
        }
    }

    dd=daynumber;
    date New = date (mm, dd, yyyy);
    return New;
}


date date::Tomorrow()
{
    int days = Date2DayNumber()+1;
    date NewDate;
    NewDate.DayNumber2Date(days);
    return NewDate;
}


/*iostream operator functions*/
//Get date:
//friend istream& operator >> (istream& out, const Date& dmy);

//print date:
ostream& operator <<(ostream& out, const date& dmy)
{
    out<<dmy.mm<<"/"<<dmy.dd<<"/"<<dmy.yyyy;
    return out;
}

/*operator functions */
date operator+ (date& LHS, int RHS)
{
    int days = LHS.Date2DayNumber();
    days = days+RHS;
    date NewDate;
    NewDate = NewDate.DayNumber2Date(days);
    return NewDate;
}

date operator - (date& LHS, int RHS)
{
    int days = LHS.Date2DayNumber();
    days = abs(days - RHS);
    date NewDate;
    NewDate = NewDate.DayNumber2Date(days);
    return NewDate;
}

int operator - (date& LHS, date& RHS)
{
    int LHS_days = LHS.Date2DayNumber();
    int RHS_days = RHS.Date2DayNumber();
    int diff = abs(LHS_days - RHS_days);
    return diff;
}

