#include "countertype.h"
#include <iostream>

using namespace std;

//Counstructor default
CounterType::CounterType():count(0),error(0)
{
    //intend to leave blank
}

CounterType::CounterType(int start): count(start), error(0)
{
    //check error
    if (count<0)
    {
        error = 1;
        count = 0;
    }
}


//Mutator
void CounterType::set(int start)
{
    if (count<0)
    {
        error = 1;
        count = 0;
    }
    count = start;
}

//Accessor
int CounterType::get()
{
    return count;
}


//Member functions
int CounterType::up()
//precondition: this function uses the count @ a point and increment the count by1
//post condition: count = count +1 and check for error even if you think there shouldn't be
{

    if (count <0)
    {
        error =1;
        count = 0;
    }
    count+=1;
    return count;
}

int CounterType::down()
//precondition: decrease the count
//Post codition: the return should be count -1 and  return as a countertype
//               if the new count is negative, the function should call error and let the main know about this
{
    if (count <0)
    {
        error =1;
        count = 0;
    }
    count -=1;
    return count;
}


//Error Functions
int CounterType::Error()
{
    return error;
}

void CounterType::Clear()
{
    error =0;
}

string CounterType::ErrorDescr(int e)
//e is the function error return value only when e =1 that's the
{
    switch(e)
    {
        case 1:
            return "Nagative Value Error";
        default:
            return "Unknown Error";
    }
}
