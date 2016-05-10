/**
 * Ke Wei
 * Project: Functors Passing to class and function
 *          * passing functor to classes
 *          * default template arguments
 *          * static constants
 * Date created: 13 Marh 2016
 *
 */


#include "../../!IncludeToolKit/Functors/functorarray.h"
//#include "../../!IncludeToolKit/Functors/simplefctors.h"
#include <iostream>
using namespace std;

void Test_Pass2Fxn();
void Test_Pass2Class();



int main()
{
    cout << "=======================================" << endl;
    Test_Pass2Fxn();
    Test_Pass2Class();
    cout << " ==================END==================" << endl;

    return 0;
}

void Test_Pass2Fxn(){
    const int MAX = 10;
    int a[MAX];
    cout<<"----------Passing to Function----------"<<endl;
    FillIn(a, MAX);
    Print(a, MAX);

    cout<<endl<<"Ascending...."<<endl;
    Sort(a, MAX, Bigger<int>());
    Print(a, MAX);

    cout<<endl<<"Decending...."<<endl;
    Sort(a, MAX, Smaller<int>());
    Print(a, MAX);
}


void Test_Pass2Class(){

    cout<<"----------Passing to Class----------"<<endl;
    cout<<"Ascending...."<<endl;
    FunctorArray<int, Bigger<int> > a;
    a.PrintArray();
    a.SortArray();
    a.PrintArray();

    cout<<"Decending...."<<endl;
    FunctorArray<int, Smaller<int> > b;
    b.PrintArray();
    b.SortArray();
    b.PrintArray();

}
