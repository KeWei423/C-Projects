//File: Array Classes (Partial + 2D + Nav Classes)
//Author: Ke Wei
//Objective: 1. There are 4 classes one is buil on top of the other one.
//           2. Each class will be tested from one function
//Last Date Modified: 10 November 2015

#include "../../Array Class Project/ClassFiles/arrayfunctions.h"
#include "../../Array Class Project/ClassFiles/partialarray.h"
#include "../../Array Class Project/ClassFiles/navigationarray.h"
#include "../../Array Class Project/ClassFiles/td_array.h"
#include "../../Array Class Project/ClassFiles/td_nav.h"
#include <iostream>

using namespace std;

//Prototypes:
//void test_partial_parray();
void test_array_navigation();
//void test_TwoD_array();
//void test_TwoD_nav();

int main()
{
    cout<<endl;
//    test_partial_parray();
    test_array_navigation();
//    test_TwoD_array();
//    test_TwoD_nav();
    cout << "=======================END=======================" << endl;
    return 0;
}

//===============
// Partial Array
//===============
void test_partial_parray()
{
    const int NumUsed=5;
    int array[]={1,2,3,4,5};
    PartialArray PA(array, NumUsed);
    bool quit = false;
    char choice;
    int item;
    int pos;
    bool success;
    int search_pos;

    cout<<"---------------Partial Array---------------"<<endl;

    cout<<"[1]Append\n"
          "[2]Search\n"
          "[3]Shift Left\n"
          "[4]Shift Right\n"
          "[5]Insert Before\n"
          "[6]Insert After\n"
          "[7]Delete\n"
          "[8]Sort\n"
          "[9]Delete Repeats\n"
        <<endl<<"E[X]xit"<<endl<<endl;

    //print this Partial Array
    cout<<PA<<endl<<endl;

    while(!quit)
    {
        cout<<": "; cin>>choice;
        switch(toupper(choice))
        {
        case '1':
            success=PA._Append(6);
            cout<<PA<<(success?" ":"X")<<endl;
            break;
        case '2':
            cout<<">>"; cin>>item;
            search_pos=PA._Search(item);
            //fail:-1
            if(search_pos >=0)
            {
                cout<<"Position: "<<search_pos<<endl;
            }
            else
            {
                cout<<item<<" is not in array"<<endl;
            }
            break;
        case '3':
            cout<<"??"; cin>>pos;
            success=PA._ShiftLeft(pos);
            cout<<PA<<(success?"OK":"Empty")<<endl;
            break;
        case '4':
            cout<<"??"; cin>>pos;
            success=PA._ShiftRight(pos);
            cout<<PA<<(success?"OK":"Full")<<endl;
            break;
        case '5':
            cout<<"??"; cin>>pos;
            cout<<">>"; cin>>item;
            success=PA._InsertBefore(pos, item);
            cout<<PA<<(success?"OK":"Full")<<endl;
            break;
        case '6':
            cout<<"??"; cin>>pos;
            cout<<">>"; cin>>item;
            success=PA._InsertAfter(pos, item);
            cout<<PA<<(success?"OK":"Full")<<endl;
            break;
        case '7':
            cout<<">>"; cin>>pos;
            success=PA._Delete(pos);
            cout<<PA<<(success?"OK":"X")<<endl;
            break;
        case '8':
            PA._Sort();
            break;
        case '9':
            PA._DeletRepeats();
            break;
        case 'X':
            quit = true;
            break;
        default:
            cout<<"["<<choice<<"] Invalid"<<endl;
            break;
        }

    }
}


//==================
// Array Navigation
//==================
void test_array_navigation()
{
    const int NumUsed=5;
    int array[]={1,2,3,4,5};
    NavigationArray AN(array, NumUsed);
    char choice;
    bool success;
    int item, pos;
    bool quit = false;

    cout<<"---------------Array Navigation---------------"<<endl;
    cout<<"[A]ppend [I]nsert    [D]elete \n"
        <<"[S]earch [4]Left     [6]right        e[X]it"<<endl;
    cout<<endl<<AN<<endl;

    while(!quit)
    {
        cout<<": "; cin>>choice;
        switch (toupper(choice))
        {
            case '4':
                success=AN.Left();
                cout<<AN<<(success?" ":"X")<<endl;
                break;
            case '6':
                success=AN.Right();
                cout<<AN<<(success?" ":"X")<<endl;
                break;
            case 'A':
                success=AN.Append_AN(6);
                cout<<AN<<(success?"OK":"Full")<<endl;
                break;
            case 'I':
                cout<<">>"; cin>>item;
                success=AN.Insert_AN(item);
                cout<<AN<<(success?"OK":"Full")<<endl;
                break;
            case 'D':
                success=AN.Delete_AN();
                cout<<AN<<(success?"OK":"Empty")<<endl;
                break;
            case 'S':
                cout<<">>"; cin>>item;
                pos=AN.Search_AN(item);
                if(pos >=0)
                {
                    cout<<"Position: "<<pos<<endl;
                }
                else
                {
                    cout<<item<<" is not in array"<<endl;
                }
                break;
            case 'X':
                quit = true;
                break;
            default:
                cout<<"["<<choice<<"] Invalid"<<endl;
                break;
        }
    }

}


//==========
// 2D Array
//==========
void test_TwoD_array()
{
    TD_array thisTwoD;
    bool quit = false;
    char choice;
    int item;
    int pos_r, pos_c;
    bool success;
    cout<<"---------------Array Navigation---------------"<<endl;

    cout<<"[1]Append\n"
          "[2]Search\n"
          "[3]Shift Right\n"
          "[4]Shift Left\n"
          "[5]Insert Before\n"
          "[6]Insert After\n"
          "[7]Delete\n"
        <<endl<<"E[X]xit"<<endl;
    cout<<thisTwoD<<endl;
    while(!quit)
    {
        cout<<": "; cin>>choice;
        switch(toupper(choice))
        {
            case '1':
                success=thisTwoD.Append_TA(1,6);
                cout<<thisTwoD<<(success?" ":"X")<<endl;
                break;
            case '2':
                cout<<">>"; cin>>item;
                thisTwoD.Search_TA(item, pos_r, pos_c);
                cout<<"Position R: "<<pos_r<<" C: "<<pos_c<<endl;

                break;
            case '3':
                cout<<"??"; cin>>pos_r>>pos_c;
                success=thisTwoD.ShiftLeft_TA(pos_r,pos_c);
                break;
            case '4':
                cout<<"??"; cin>>pos_r>>pos_c;
                success=thisTwoD.ShiftRight_TA(pos_r, pos_c);
                break;
            case '5':
                cout<<"??"; cin>>pos_r>>pos_c;;
                cout<<">>"; cin>>item;
                success=thisTwoD.InsertBefore_TA(pos_r,pos_c,item);
                break;
            case '6':
                cout<<"??"; cin>>pos_r>>pos_c;
                cout<<">>"; cin>>item;
                success=thisTwoD.InsertAfter_TA(pos_r, pos_c, item);
                break;
            case '7':
                cout<<">>"; cin>>pos_r>>pos_c;
                success=thisTwoD.Delete_TA(pos_r, pos_c);
                break;
            case 'X':
                quit = true;
                break;
            default:
                cout<<"["<<choice<<"] Invalid"<<endl;
                break;
        }
    }

}


//===============
// 2D Navigation
//===============
void test_TwoD_nav()
{
    TD_Nav thisNav;
    char choice;
    bool success;
    int item;
    bool quit = false;
    cout<<"---------------2D Navigation---------------"<<endl;
    cout<<"[A]ppend [I]nsert    [D]elete    [S]earch\n"
        <<"[4]Left  [6]right    [8]Up       [2]down        e[X]it"<<endl;

    cout<<endl<<thisNav<<endl;

    while(!quit)
    {
        cout<<": "; cin>>choice;
        cout<<"----"<<endl;
        switch (toupper(choice))
        {
            case '4':
                success=thisNav.Left_TN();
                cout<<thisNav<<(success?" ":"X")<<endl;
                break;
            case '6':
                success=thisNav.Right_TN();
                cout<<thisNav<<(success?" ":"X")<<endl;
                break;
            case '8':
                success=thisNav.Up_TN();
                cout<<thisNav<<(success? "":"Top")<<endl;
                break;
            case '2':
                success=thisNav.Down_TN();
                cout<<thisNav<<(success?" ":"Buttom")<<endl;
                break;
            case 'A':
                cout<<">>"; cin>>item;
                success=thisNav.Append_TN(item);
                cout<<thisNav<<(success?" ":"Full")<<endl;
                break;
            case 'I':
                cout<<">>"; cin>>item;
                success=thisNav.Insert_TN(item);
                cout<<thisNav<<(success?" ":"Full")<<endl;
                break;
            case 'D':
                success=thisNav.Delete_TN();
                cout<<thisNav<<(success?" ":"Empty")<<endl;
                break;
            case 'S':
                cout<<">>"; cin>>item;
                success=thisNav.Search_TN(item);
                cout<<thisNav<<(success?" ":"Item not find")<<endl;
                break;
            case 'X':
                quit = true;
                break;
            default:
                cout<<"["<<choice<<"] Invalid"<<endl;
                break;
        }
    }
}
