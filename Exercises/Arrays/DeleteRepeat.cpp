//Name: Ke Wei
//Date Created: 11 Januaray 2015
//Project: 7.3 Delete Repeate
/*         Delete the repeates that has partially filled array of characrters a sa formal parameter and tha
           deletes all the repeeated letteres from the array.*/
//Notes:
/*
 */

//Last Date Modified: 19 January 2015

#include <iostream>

using namespace std;

//constants
const int SIZE =10;

int StrLen(const char source[]);
void DeleteRepeate(char source[], int& len);
int Search(const char source[], char target);
int Delete(char source[], int &size, int pos);
int ShiftLeft(char source[], int& size, int pos);
void Sort(char source[], int len);



int main()
{
    cout << "=================Start================="<<endl;
    //delcare character array
    char s[SIZE]="abcde";
    cout<<"Before: "<<s<<endl;
    int length=StrLen(s);
    DeleteRepeate(s, length);
    Sort(s, length);
    cout<<"After: "<<s<<endl<<endl;

    char s2[SIZE]="aabcde";
    cout<<"Before: "<<s2<<endl;
    int length1=StrLen(s2);
    DeleteRepeate(s2, length1);
    Sort(s2, length1);
    cout<<"After: "<<s2<<endl<<endl;


    char s3[SIZE]="abc2dcba";
    cout<<"Before: "<<s3<<endl;
    int length2=StrLen(s3);
    DeleteRepeate(s3, length2);
    Sort(s3, length2);
    cout<<"After: "<<s3<<endl<<endl;

    char s4[SIZE]="aabcdd";
    cout<<"Before: "<<s4<<endl;
    int length3=StrLen(s4);
    DeleteRepeate(s4, length3);
    Sort(s4, length3);
    cout<<"After: "<<s4<<endl;
    cout << "=================End=================" << endl;
    return 0;
}



//Preconditon: char array c[] with certain length;
int StrLen(const char source[])
//post condition: return the length of c[]
{
    int len=0;
    if(source[len]=='\0')
    {
        return false;
    }

    while(source[len]!='\0')
    {
        len++;
    }
    return len;
}


//delete find the repeate and delete the repeate
void DeleteRepeate(char source[], int& len)
//delete the repeate
{
    int temp_pos;
    int i=len-1;
    while(i>=0)
    {
        temp_pos=Search(source, source[i]);
        if((i!=temp_pos)&&(temp_pos!=-1))
        {
            Delete(source, len, i);
        }
        else
        {
            i--;
        }
    }
}


//seach for a specific character in c[]
int Search(const char source[], char target)
//return the position of the value in c[]
{
    int i=0;
    while(source[i]!='\0')
    {
        if(source[i]==target)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}


//delete a given value
int Delete(char source[], int& size, int pos)
//return the new size and shift the all values on the right side to shift one to the left
{
    if(size>0)
    {
        ShiftLeft(source, size, pos);
        return true;
    }
    else
    {
        return false;
    }
}



//shift all values to the left from that position
int ShiftLeft(char source[], int& size, int pos)
{
    if(size>0)
    {
        for(int i=pos; i<=size; i++)
        {
            source[i]=source[i+1];
        }
        size -=1;
        return true;
    }
    else
    {
        return false;
    }
}


//rearrage the letters in acceding order
void Sort(char source[], int len)
//sort the c[] in the way that the content is abc....
{
    for(int i=len-1; i>0; i--)
        for(int j=0; j<i; j++)
        {
            if(source[j]>source[j+1])
            {
                char temp=source[j+1];
                source[j+1]=source[j];
                source[j]=temp;
            }
        }
}
