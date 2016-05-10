//File Name: dec2bin
//Author: Ke Wei
//Objective: a program will convert number with base 10 to number with base 2.
//           the print out should be 16bit binary equivalent of the number.
//           for example: 18=0000 0000 0001 0010
//Date created: 23 October 2015
//Late date modifed: 28 October 2015

//Notes:
/* this program only takes positive decimal numbers. To represent negative numbers, it's learnd thought
   2's complement
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

void dec2bin(int n);

int main()
{
    cout<<endl;

    int number;
    char answer = 'y';

    do
    {
    cout<<"Decimal: ";    cin>>number;
    cout<<"Binary: ";
    dec2bin(number);

    cout<<endl<<"Again?"<<endl;
    cin>>answer;
    cout<<endl;

    }while((answer=='y') || (answer =='Y'));
    cout<<"==================END================"<<endl;
    return 0;
}


void dec2bin(int n)
{
    int pow2;
    int bin;
    int counter =0;

    pow2=pow(2.0, 15.0);

    while(pow2 )
    {
        bin = n - pow2;
        if(bin< 0)
        {
            cout<<0;
        }
        else
        {
            cout<<1;
            n=bin;
        }
        pow2 /=2;

        counter +=1;
        if (counter%4 == 0)
        {
            cout<<" ";
        }
    }

}
