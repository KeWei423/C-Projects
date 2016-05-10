//=================================================
// Notes on Referece, Exception Handling, Template
//=================================================

#include <iostream>
#include <string>
using namespace std;

void Print(int* a, int size);

//Get Pointer fucntion
void TestGet();
int *Get(int *a, int size, int key);

//Get Reference function
void TestRef();
int &GetRef(int* a, int size, int key);

//typedrf
void TestItemType();
typedef string ITEM_TYPE; // you can change type here!
ITEM_TYPE* GetItemType(ITEM_TYPE* a, int size, ITEM_TYPE key);
void PrintItemType(ITEM_TYPE* a, int size);

//Templete
void TestTemplate();
template <typename ITEM_TYPE>
ITEM_TYPE* GetTemplate(ITEM_TYPE* a, int size, ITEM_TYPE key);
template <typename ITEM_TYPE>
void PrintTemplate(ITEM_TYPE* a, int size);




int main()
{
    cout <<endl<< "------------------------------" << endl<<endl;
//    TestGet();
//    TestRef();
//    TestItemType();
    TestTemplate();
    cout <<endl<< "==================================" <<endl;
    return 0;
}


//================
// Print function
//================
void Print(int *a, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<endl;
}


//=========================
// Get pointer function
//=========================
void TestGet(){
    int a[10] = {2,4,6,8};
    int* pos = Get(a, 4, 4);
    if (pos){ //pos != NULL
        cout<<*pos<<" was found at pos: "<<pos-a<<endl;
    }
    else{
        cout<<"item not found"<<endl;
    }
}


int* Get(int *a, int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(*a == key)
        {
            return a;
        }
        a++;
    }
    return NULL;
}


//=========================
// Get reference function
//=========================
int &GetRef(int *a, int size, int key)
{
    for(int i = 0; i<size; i++)
    {
        if(*a == key)
        {
            return *a;
        }
        a++;
    }
    throw 0;
}

void TestRef()
{
    int a[10]={2,4,6,8};
    try{
        //place 5 at location 8 for array a with 4 size big
        GetRef(a, 4, 8) = 5;
        Print (a, 4);
    }
    catch(int)
    {
        cout<<"Invalid Reference!"<<endl;
    }
}

//==================
// Test for typedef
//==================
void TestItemType()
{
//    int a[10]={2,4,6,8};
//    int* pos =GetItemType(a, 4, 6);
//    if(pos)
//    {
//        cout<<*pos<<" was found at "<<pos-a<<endl;
//    }
//    else
//    {
//        cout<<"Item not found"<<endl;
//    }



    string b[10]= {"000","111","222","333"};
    PrintItemType(b, 4);
    string *pos2 = GetItemType(b, 4, "111");
    if(pos2)
    {
        cout<<*pos2<<" was found at "<<pos2-b<<endl;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
}

ITEM_TYPE* GetItemType(ITEM_TYPE *a, int size, ITEM_TYPE key)
{
    for(int i=0; i<size; i++)
    {
        if(*a == key)
        {
            return a;
        }
        a++;
    }
    return NULL;
}


void PrintItemType(ITEM_TYPE *a, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<endl;
}


//==================
// Test for Template
//==================
template <typename ITEM_TYPE>
ITEM_TYPE* GetTemplate(ITEM_TYPE* a, int size, ITEM_TYPE key)
{
    for(int i=0; i<size; i++)
    {
        if(*a == key)
        {
            return a;
        }
        a++;
    }
    return NULL;
}

template <typename ITEM_TYPE>
void PrintTemplate(ITEM_TYPE* a, int size)
{
    for(int i=0; i<size; i++, a++)
    {
        cout<<*a<<" ";
    }
    cout<<endl;
}

void TestTemplate()
{
    int a[10]={2,4,6,8};
    int* pos =GetTemplate(a, 4, 6);
    if(pos)
    {
        cout<<*pos<<" was found at "<<pos-a<<endl;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }



    string b[10]= {"000","111","222","333"};
    PrintTemplate(b, 4);
    string *pos2 = GetTemplate(b, 4, string("111"));
    if(pos2)
    {
        cout<<*pos2<<" was found at "<<pos2-b<<endl;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
}
