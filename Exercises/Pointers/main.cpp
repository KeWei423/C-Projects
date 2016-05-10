//Project: Delete Repeat with ptrs
//Author: Ke Wei
//Date Created: 21 Januaray 2016
//Objective: re-implement the DeleteRepleat function that only uses pointer to delete duplicate in ctring.
//Last Date Modified: 26 Januaray 2016

#include <iostream>
#include <cstring>
using namespace std;

char* DeleteRepeat(char *source);
bool SearchRepeat(char target, char *New, char* NewWalker);


int main()
{
    char numb[]="12345666666";
    char *aftrNumb;
    cout << "------------------------" << endl;
    aftrNumb=DeleteRepeat(numb);
    cout<<"Before: "<<numb<<endl;
    cout<<" After: "<<aftrNumb<<endl;
    delete []aftrNumb;

    char numb1[]="11111123456";
    char *aftrNumb1;
    cout << "------------------------" << endl;
    aftrNumb1=DeleteRepeat(numb1);
    cout<<"Before: "<<numb1<<endl;
    cout<<" After: "<<aftrNumb1<<endl;
    delete []aftrNumb1;

    char numb2[]="123456";
    char *aftrNumb2;
    cout << "------------------------" << endl;
    aftrNumb2=DeleteRepeat(numb2);
    cout<<"Before: "<<numb2<<endl;
    cout<<" After: "<<aftrNumb2<<endl;
    delete []aftrNumb2;

    char numb3[]="2222222222222";
    char *aftrNumb3;
    cout << "------------------------" << endl;
    aftrNumb3=DeleteRepeat(numb3);
    cout<<"Before: "<<numb3<<endl;
    cout<<" After: "<<aftrNumb3<<endl;
    delete []aftrNumb3;


    char numb4[]="12341234";
    char *aftrNumb4;
    cout << "------------------------" << endl;
    aftrNumb4=DeleteRepeat(numb4);
    cout<<"Before: "<<numb4<<endl;
    cout<<" After: "<<aftrNumb4<<endl;
    delete []aftrNumb4;

    char numb5[]="11223455";
    char *aftrNumb5;
    cout << "------------------------" << endl;
    aftrNumb5=DeleteRepeat(numb5);
    cout<<"Before: "<<numb5<<endl;
    cout<<" After: "<<aftrNumb5<<endl;
    delete []aftrNumb5;


    cout<< "============END===========" <<endl;
    return 0;
}


//Delete repeat function
char* DeleteRepeat(char *source)
{
    //1.create source origin pointer
//    char *SrcOrigin = source;

    //2. Create new pointer to hold the cstring without repeat
    int len = strlen(source);
    char *Dest = new char [len];

    //3. create walkers for both cstrings
    char *SrcWalker = source;
    char *DstWalker = Dest;

    while(*SrcWalker !='\0')
    {
        bool repeat = SearchRepeat(*SrcWalker, Dest, DstWalker);
        if(repeat == false)
        //there is no repeate
        {
            //4a. Assinge the value to dest
            *DstWalker = *SrcWalker;
            DstWalker++;
            SrcWalker++;
        }
        else //repeate == true
        {
            SrcWalker++;
        }
    }
    *DstWalker = '\0';
//    delete []SrcOrigin;
    source = Dest;
    return source;
}


//check if if the target char that the specific memory location
//has the same value as any value of the new char
bool SearchRepeat(char target, char *New, char *NewWalker)
{
    char *NewStart = New;
    int diff = NewWalker - New;
    for(int i=0; i<diff; i++)
    {
        if(target == *NewStart)
        {
            return true;
        }
        else
        {
            NewStart++;
//            cout<<"Test3"<<endl;
        }
    }
    return false;
}
