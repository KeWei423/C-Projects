//File: Couter2
//Author: Ke Wei
//Objective: a counter should be staring at 0. A user will press +/- as commands to increae or decrease the counts.
//           Few restrictions: 1)counter starts at 0 2) 0 cannot decrement to negative count if this happens error
//           will be find and reset the counter count to 0
//Date: 15 October 2015

//Note:
/*Error functions are a serise of three functions
 *
 *
 */

#include <iostream>
#include "countertype.h"

using namespace std;

int main()
{
    cout<<endl<<endl;
    char choice;
    bool quit = false;
    CounterType counter,temp;

    cout<<counter.get()<<endl;

    cout<<"[U]p     [D]own          [Q]uit"<<endl;

    while(!quit)
    {
        cout<<": "; cin>>choice;
        switch(choice)
        {
            case 'U':
            case 'u':
                temp = counter.up();
                if(temp.Error())
                {
                    cout<<temp.ErrorDescr(temp.Error())<<endl;
                    cout<<"Rest object to default"<<endl;
                    temp.Clear();
                }
                cout<<temp.get()<<endl;
                break;
            case 'D':
            case 'd':
                temp = counter.down();
                if(temp.Error())
                {
                    cout<<temp.ErrorDescr(temp.Error())<<endl;
                    cout<<"Rest object to default"<<endl;
                    temp.Clear();
                }
                cout<<temp.get()<<endl;
                break;
            case 'Q':
            case 'q':
                quit = true;
                break;
            default:
                cout<<"["<<choice<<"] is not a valid input"<<endl;
                break;
        }
    }
    cout << "===================END===================" << endl;
    return 0;
}
