#include "arrayfunctions.h"

#include <iostream>

using namespace std;

//=================
//Default Functions
//=================
void initialize(ITEM_TYPE a[], int size)
{
     for(int i=0; i<size; i++)
     {
         a[i]=i*5;
     }
}


void Print(ITEM_TYPE a[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int Search(ITEM_TYPE a[], int size, ITEM_TYPE number)
{
    for(int i=0; i<size; i++)
    {
        if (number==a[i])
        {
            return i;
        }
    }
    return -1;
}


//===============================
//Array Manipulation Functions:
//===============================
int Append(ITEM_TYPE a[], int &size, ITEM_TYPE number)
{
    if(size <MAX)
    {

        a[size]=number;
        size +=1;
        return true;
    }
    else
    {

        return false;
    }
}


int ShiftRight(ITEM_TYPE a[], int &size, int Position)
{
    if(size <MAX)
    {
        for(int i=size; i!=Position; i--)
        {
            a[i]=a[i-1];
        }
        size ++;
        return true;
    }
    else
    {

        return false;
    }
}


int ShiftLeft(ITEM_TYPE a[], int& useNumber, int position)
{
    if(useNumber >0)
    {
        for (int i=position; i<=useNumber; i++)
        {
            a[i]=a[i+1];
        }
        useNumber -= 1;
        return true;
    }
    else
    {
        return false;
    }
}


int InsertBefore(ITEM_TYPE a[], int& size, int position, ITEM_TYPE number)
{
    int temp;
    temp= ShiftRight(a,size,position);
    a[position]=number;
    return temp;
}


int InsertAfter(ITEM_TYPE a[], int& size, int position, ITEM_TYPE number)
{
    int temp;
    temp=ShiftRight(a,size,position);
    a[position +1]=number;
    return temp;
}

int Delete(ITEM_TYPE a[], int& size, int position)
{
    if(size >0)
    {
        ShiftLeft(a,size,position);
        return true;
    }
    else
    {
        return false;
    }
}

//===============================
//More Advanced Array Functions:
//===============================
void Reverse(ITEM_TYPE a[], int size)
{
    int i=0;
    int temp;
    size = size-1;

    while (i != size)
    {
        temp = a[i];
        a[i]=a[size];
        a[size]=temp;
        i++;
        size--;
    }
}


void Sort(ITEM_TYPE a[], int size)
{
    //this is the bubble sort program
    //this function brings the largest number towards the right
    for(int i = size -1; i>0; i--)
        for(int j=0; j<i; j++)
            if(a[j]>a[j+1])
            {
                //swarp numbers
                int temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
}


void DeleteRepeats(ITEM_TYPE a[], int& size)
{
    int temp_position;
    for(int i=size-1; i>=0;i--)
    {
       temp_position = Search(a, size, a[i]);
       if(i!=temp_position)
       {
           Delete(a, size, i);
       }

    }
}


void Copy(const ITEM_TYPE original[], ITEM_TYPE duplicate[], int size)
{
    for(int i=0; i<size; i++)
    {
        duplicate[i]=original[i];
    }
}

//==========================
//Error checking function:
//==========================
string ErrorDescr(int e)
{
    switch(e)
    {
        case 0:
            return "OK";
        case -1:
            return "Error: Finding not in array";
        case -2:
            return "Error: Exceed maximum array capacity";
        case -3:
            return "Error: Array position is negative.";
        case -4:
            return "Error: Empty";
        default:
            return "Error: Unknow.";
    }
}

