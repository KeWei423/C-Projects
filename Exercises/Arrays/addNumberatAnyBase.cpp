//Name: Ke Wei
//Date Created: 11 Januaray 2016
//Project: 7.2 & 7.7 Add Nubmers at Any base
/*         The program perforoms addition of 2 numbers at any base up to 10 digits
           Using cstring to store these 2 numbers.
           Repeate this calculation as many times as the user wants */
//Notes:
/* Here are few things we need to assume:
   1. The numbers inputed are less than base to fulfill the counting requirement
   2. The laregest base counts up to 16. IT is the maxium base number
 */

//Last Date Modified: 19 Januaray 2016

#include <cstring>
#include <iostream>

using namespace std;

//GLOBAL CONSTANTS:
const char BASE[]="0123456789ABCDEF";
const int SIZE=3;

//PROTOTYPES:
void FxnTest(char s1[], char s2[], int base);
void Pad(char number[], char target);
void ShiftRight(char number[], int &length, int pos);
int Dig2Int(char target, int base);
char Int2Dig(int index, int base);
bool Add(char N1[], char N2[], char R[], int base);
//void unPad(char source[]);
//int FindFirstNotOf(char source[], char target, int pos);
//int Find(const char source[], const char target, int pos=0);
//int StrChr(const char source[], char target, int pos);
//void ShiftLeft(char source[], int &length, int pos);
void ShowResult(bool result, char numb1[], char numb2[], char r[]);


int main()
{
    //Declare variables

    char R[SIZE];
    bool OF;

    //----------------
    // Function Test
    //----------------
//    FxnTest(N1, N2, base);

cout << "----------------------------------------------" << endl;
    cout<<"Assumptions:\n"
          "1. the value of each digit of N1 and N2 must be less than base value\n"
          "2. the maximum base number is 16"<<endl<<endl;

    //Sum of 2 numbers
    int base1=8;
    cout<<"Base: "<<base1<<endl;
    char N1[SIZE]="1";
    char N2[SIZE]="6";
    OF=Add(N1, N2, R, base1);
    ShowResult(OF, N1, N2, R);

    char N3[SIZE]="7";
    OF=Add(N2, N3, R, base1);
    ShowResult(OF, N2, N3, R);

    char N4[SIZE]="75";
    OF=Add(N3, N4, R, base1);
    ShowResult(OF, N3, N4, R);


    cout<<endl;
    int base2=10;
    cout<<"Base: "<<base2<<endl;
    char N5[SIZE]="11";
    char N6[SIZE]="12";
    OF=Add(N5, N6, R, base2);
    ShowResult(OF, N5, N6, R);

    char N7[SIZE]="49";
    OF=Add(N7, N6, R, base2);
    ShowResult(OF, N7, N6, R);

    char N8[SIZE]="99";
    OF=Add(N8, N6, R, base2);
    ShowResult(OF, N8, N6, R);

    cout<<endl;
    int base3=16;
    cout<<"Base: "<<base3<<endl;
    char N9[SIZE]="5";
    char N10[SIZE]="1";
    OF=Add(N9, N10, R, base3);
    ShowResult(OF, N9, N10, R);

    char N11[SIZE]="A";
    OF=Add(N9, N11, R, base3);
    ShowResult(OF, N9, N11, R);

    char N12[SIZE]="F";
    OF=Add(N11, N12, R, base3);
    ShowResult(OF, N11, N12, R);

    char N13[SIZE]="11";
    char N14[SIZE]="15";
    OF=Add(N13, N14, R, base3);
    ShowResult(OF, N13, N14, R);

    char N15[SIZE]="5A";
    OF=Add(N13, N15, R, base3);
    ShowResult(OF, N13, N15, R);

    char N16[SIZE]="6E";
    OF=Add(N16, N15, R, base3);
    ShowResult(OF, N16, N15, R);


    char N17[SIZE]="AF";
    char N18[SIZE]="A1";
    OF=Add(N17, N18, R, base3);
    ShowResult(OF, N17, N18, R);

    cout <<"=================END================="<<endl;
    return 0;
}


//----------------
// Function Test
//----------------
void FxnTest(char s1[], char s2[], int base)
{
    cout<<"===Test for Pading==="<<endl;
    cout<<"Before: "<<s1<<endl;
    Pad(s1, '0');
    cout<<"After: "<<s1<<endl;

    cout<<"Before: "<<s2<<endl;
    Pad(s2, '0');
    cout<<"After: "<<s2<<endl;

    cout<<endl<<"===Test for Dig Int Conversion==="<<endl;
    int r1=Dig2Int(s1[2], base);
    cout<<s1[2]<<" = "<<r1<<" in base "<<base<<endl;

    char temp=Int2Dig(13, 16);
    cout<<"13 = "<<temp<<" in base 16"<<endl;

//    cout<<endl<<"===Test for unPading==="<<endl;
//    cout<<"Before: "<<s1<<endl;
//    int pos=StrChr(s1, '0', 0);
//    cout<<"0 is in pos: "<<pos<<endl;

//    int Find_pos=Find(s2, '0', 0);
//    cout<<"Find 1 in N1: "<<Find_pos<<endl;

//    int FirstNotPos=FindFirstNotOf(s2, '0', 0);
//    cout<<"Pos of first non zero: "<<FirstNotPos<<endl;
}



//=================
//Pading functions
//=================
void Pad(char number[], char target)
// Pading will push all values of the array to the end of the array
{
    int len=strlen(number);
    int zeros=SIZE-len;
    while(zeros>1)
    {
        //insert zeros to aline all value to the right
        ShiftRight(number, len, 0);
        number[0]=target;
        zeros--;
    }
}


void ShiftRight(char number[], int& length, int pos)
{
    for(int i=length;i!=pos;i--)
    {
        number[i]=number[i-1];
    }
    length++;
}


//==========
// Addition
//==========
bool Add(char N1[], char N2[], char R[], int base)
{
    Pad(N1, '0');
    Pad(N2, '0');
    int n1, n2, sum,r;
    int c=0;
    char D;
    for(int i=SIZE-2; i>=0; i--)
    {
//        n1=N1[i]-'0';
        n1=Dig2Int(N1[i], base);
//        n2=N2[i]-'0';
        n2=Dig2Int(N2[i], base);
        sum=n1+n2+c;
        c=sum / base;
        r=sum % base;
        D=Int2Dig(r, base);
        R[i]=D;
//        cout<<"c"<<i<<": "<<c<<endl;
    }
    R[SIZE-1]='\0';
//    cout<<"c"<<c<<endl;
    if(c==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


//================
//unPad functions
//================
//void unPad(char source[])
//{
//    int pos = FindFirstNotOf(source, 0, 0);
//    int len=strlen(source);
//    ShiftLeft(source, len, pos);
//}


//int FindFirstNotOf(char source[], char target, int pos)
//{
//    int result;
//    while(source[pos]!='\0')
//    {
//        result=Find(source, target);
//        if(result==-1)
//        {
//            pos++;
//        }
//        else
//        {
//            return pos;
//        }
//    }
//    return -1;
//}


//int Find(const char source[], const char target,int pos)
//{
//    int index;
//    index=StrChr(source, target, pos);
//    return index;
//}


int StrChr(const char source[], char target, int pos)
{
    int i=pos;
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

//void ShiftLeft(char source[], int& length, int pos)
//{
//    while(length>=0)
//    {
//        for(int i=pos; i<=length; i++)
//        {
//            source[i]=source[i+1];
//        }
//        length--;
//    }
//}

//======================
//Digit Int conversions
//======================
int Dig2Int(char target, int base)
{
    int index=0;
    while(index<base)
    {
        if(target == BASE[index])
        {
            return index;
        }
        else
        {
            index++;
        }
    }
    return -1;
}


char Int2Dig(int index, int base)
{
    char target;
    if(index<=base)
    {
        target=BASE[index];
    }
    else
    {
        target='!';
    }
    return target;
}


//======================
// check base and input
//======================
bool check_input(char source[], int base)
{
    int n;
    for(int i=0; i<(int)strlen(source); i++)
    {
        n=Dig2Int(source[i], base);
        if(n>base)
        {
            return false;
        }
    }
    return true;
}


bool check_base(int base, int numb)
{
    if(base>numb)
    {
        return false;
    }
    return true;
}


void ShowResult(bool result, char source1[], char source2[], char r[])
{
    cout<<source1<<"+"<<source2<<"=";
    if(result==true)
    {
        cout<<r<<endl;
    }
    else
    {
        cout<<"Error: Overflow"<<endl;
    }
}
