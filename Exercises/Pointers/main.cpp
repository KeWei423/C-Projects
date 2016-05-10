//Author: Ke Wei
//Project: 9.6 Add Entry
//Date created: 21 Januarary 2016
//Objective: Write a program that creates a dynamic array of five strings.
//           Store five names of your choice into the dynamic array.
//           Next, complete an add and delete function

//Note:
/* using functions CopyList, Search, Allocate, Initialize, and print for the list
 * leave no pointers hangging , pass by reference
 */

//Last Date modified: 26 Januaray 2016

#include <iostream>
using namespace std;
string *Allocate(int size);
void Initialize(string *ptr);
void Print(string *ptr, int size);
void CopyList(string *source, string *dest, int count);
string *Add(string* &ptr, int& size, string add);
int Search(string *source, string target, int size);
//void FillIn(string *source, string *NewEntry, int size, int pos);
string *Delete(string *&source, int& size, string del);

int main()
{
    int size = 5;
    string *sptr;
    cout<<"------------------------"<<endl<<endl;
    sptr=Allocate(size);
    Initialize(sptr);
    cout<<"Original: ";
    Print(sptr, size);
    cout<<endl<<endl;

    cout<<"Add \"Six\" to the end of the entry"<<endl;
    sptr = Add(sptr, size, "Six");
    cout<<"Add: ";
    Print(sptr, size);
    cout<<endl<<endl;

    cout<<"Delete \"Three\" from the entry"<<endl;
    sptr = Delete(sptr, size, "Three");
    cout<<"Delete: ";
    Print(sptr, size);
    delete []sptr;
    cout<<endl<<endl;


    int size1 = 5;
    string *sptr1;
    cout<<"------------------------"<<endl<<endl;
    sptr1=Allocate(size1);
    Initialize(sptr1);
    cout<<"Original: ";
    Print(sptr1, size1);
    cout<<endl<<endl;

    cout<<"Add \"Six\" to the end of the entry"<<endl;
    sptr1 = Add(sptr1, size1, "Six");
    cout<<"Add: ";
    Print(sptr1, size1);
    cout<<endl<<endl;

    cout<<"Delete \"three\" from the entry"<<endl;
    sptr1 = Delete(sptr1, size1, "three");
    cout<<"Delete: ";
    Print(sptr1, size1);
    delete []sptr1;
    cout<<endl<<endl;

    int size3 = 5;
    string *sptr3;
    cout<<"------------------------"<<endl<<endl;
    sptr3=Allocate(size3);
    Initialize(sptr3);
    cout<<"Original: ";
    Print(sptr3, size3);
    cout<<endl<<endl;

    cout<<"Add another \"Five\" to the end of the entry"<<endl;
    sptr3 = Add(sptr3, size3, "Five");
    cout<<"Add: ";
    Print(sptr3, size3);
    cout<<endl<<endl;

    cout<<"Delete \"Five\" from the entry"<<endl;
    sptr3 = Delete(sptr3, size3, "Three");
    cout<<"Delete: ";
    Print(sptr3, size3);
    delete []sptr3;
    cout<<endl<<endl;


    int size2 = 5;
    string *sptr2;
    cout<<"------------------------"<<endl<<endl;
    sptr2=Allocate(size2);
    Initialize(sptr2);
    cout<<"Original: ";
    Print(sptr2, size2);
    cout<<endl<<endl;

    cout<<"Add another \"Three\" to the end of the entry"<<endl;
    sptr2 = Add(sptr2, size2, "Three");
    cout<<"Add: ";
    Print(sptr2, size2);
    cout<<endl<<endl;

    cout<<"Delete \"Three\" from the entry"<<endl;
    sptr2 = Delete(sptr2, size2, "Three");
    cout<<"Delete: ";
    Print(sptr2, size2);
    delete []sptr2;
    cout<<endl<<endl;

    cout<<"============END=========="<<endl;
    return 0;
}

string *Allocate(int size)
{
    string *temp_ptr = new string [size];
    return temp_ptr;
}


//Filling the array with 5 string elements
void Initialize(string *ptr)
{
    *ptr="One";
    ptr++;
    *ptr="Two";
    ptr++;
    *ptr="Three";
    ptr++;
    *ptr="Four";
    ptr++;
    *ptr="Five";
    ptr++;
}

//print out the elements in string array
void Print(string *ptr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<"|"<<*ptr<<"|";
        ptr++;
    }
}


//Copy the count amount of elements from source to destination
void CopyList(string *source, string *dest, int count)
{
    for(int i=0; i<count; i++)
    {
        *dest = *source;
        dest++;
        source++;
//        cout<<"i: "<<i<<endl;
    }
//    Print(Dest,size);
//    return Dest;
}


//append a new elements to the end of the array
string *Add(string *&ptr, int &size, string add)
//the new array would have size+1 elements
{
    //1. create a new entry
    string *NewEntry=Allocate((size+1));

    //2. ptr staying at the first pos of of the original array
    string *SrcInit = ptr;

    //3. Copy from source to dest
    CopyList(ptr, NewEntry, size);

    //4. Delete the the origional source
    delete [] SrcInit;

    //5. Make a pointer pointing at end of the array
    string *End = NewEntry+size;

    //6. Append the new item to the end of the string by
    *End = add;

    //7. change size
    size++;

    //8. point the source to the new array
    ptr = NewEntry;

    return ptr;
}


//Searching for a target inside the souce
int Search(string *source, string target, int size)
//return position if found
//return -1 if not found
{
    for(int i=0; i<size; i++)
    {
//        cout<<"test"<<i<<endl;
        if(*source == target)
        {
            return i;
        }
        source++;
    }
    return -1;
}

//Filling array is used in filling array after deleting an elemnt but it's no longer needed using CopyList
//void FillIn(string *source, string *NewEntry, int size, int pos)
//{
//    for(int i=0; i<size; i++)
//    {
//        if(i!=pos)
//        {
//            *NewEntry = *source;
//            NewEntry++;
//            source++;
//        }
//        else
//        {
//            source++;
//        }
//    }
//}


//Delete an target array from souce
string *Delete(string *&source, int &size, string del)
//if the target is not in the source return the same elements in source
//if the target is in the souce then return the elements without target
{
    //1. locate the source address
    string *SrcOrigin = source;

    //2. Find the position to target in source
    int pos = Search(source, del, size);
//    cout<<"Pos: "<<pos<<endl;
    //if result is -1 that means target is not within this array return the source
    //if result is not -1 then we should create a new array that's read to filling the elements needed

    if(pos != -1)
    {
        //3. Create the new entry that's goint to fill in the new elements;
        string *NewEntry=Allocate(size-1);

        //4. used to move arround the new entry
        string *NewEntryOrigin = NewEntry;

        //5. Copy the elements from 0 until pos but does not include pos
        CopyList(source, NewEntry, pos);

        //6. move the source pointer to target position +1 and NewEntry pointer to po svalue
        source = source+pos+1;
        NewEntry=NewEntry+pos;

        //Copy the elements from after pos to the end to dest
        int count = size -pos-1;
        CopyList(source, NewEntry, count);

        //7. Delete original source
        delete [] SrcOrigin;

        //8. Making source pointing to the new pointer
        source = NewEntryOrigin;

        //9. decrease the size
        size --;
    }
    return source;
}
