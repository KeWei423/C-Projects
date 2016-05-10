//==========================
// Array Navigation Class.h
//==========================
//Purpose:
/* This class is designed to manage  a current positon on a partically filled array.
 * It will send command to PartialArray.h and keeps track of the current postion
 */
#ifndef NAVIGATIONARRAY_H
#define NAVIGATIONARRAY_H
#include "../../Array Class Project/ClassFiles/partialarray.h"
#include <iostream>

using namespace std;


class NavigationArray
{
public:
    //-------------
    // Constructors
    //-------------
    NavigationArray();
    NavigationArray(const int init[], int size);

    //-------------
    //Accessor
    //-------------
    PartialArray getPartialArray();
    int getCursor();

    //-------------
    // Mutator
    //-------------
    void setPartialArray(const int init[], int size);
    void setCursor(int position);

    //------------------
    //Service functions
    //------------------
    int Left();
    //decrement the cursor to the previous position
    //return fail code

    int Right();
    //increment the cursor to the next positon
    //return fail code

    int Insert_AN(int insertMe);
    //insert item at the current positon
    //return fail code

    int Append_AN(int appendMe);
    //append an item at the end
    //return fail code

    int Delete_AN();
    //delete curent position
    //return fail code

    int Search_AN(int key);
    //Search the key and return postion
    //or return fail code

    friend ostream& operator << (ostream& outs, const NavigationArray& print);


private:
    PartialArray thisArray;
    int cursor;
    int error_an;
};


#endif // NAVIGATIONARRAY_H
