//File Name: converting binary(base 2) to decimal(base 10) number
//Author: Ke Wei
//Ojbect: converint numerical representation from binary (base 2) to decimal (base 10)
//Date created: 22 October 2015
//Last day modified: 28 October 2015

//Notes:
/*the input binary only represent positive integers
 */

#include <iostream>
#include <cmath>

using namespace std;

int bin2dec(char binary);

int main()
{
    cout<<endl;
    char bit;
    int decimal = 0;
    int const BASE = 2;
    int temp;

    cout<<"Binary: ";
    bit = cin.get();

    while(bit !='\n')
    {
        temp = bit - '0';
        decimal = decimal * BASE + temp;
        bit = cin.get();
    }
    cout<<"Decimal: "<<decimal<<endl;
    cout<<endl;

    cout<<"==============END============="<<endl;

    return 0;
}

