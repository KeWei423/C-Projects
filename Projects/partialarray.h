//==========================
// Partial Array Class.h
//==========================
//Propose for Partial Array Class
/* This class calls the PartiallyFilledArrayFunctions.h
 * It manages the partially filled array and the number of "interesting" elements in this array
 * This class is designed based on the using the PartiallyFilledArrayFunctions file and the classes of higher order will be using the
   similiar methods which is using the cuntions the author has already written.
 */

#ifndef PARTIALARRAY_H
#define PARTIALARRAY_H
#include "../../Array Class Project/ClassFiles/arrayfunctions.h"
#include <iostream>
using namespace std;

class PartialArray
{
public:
    PartialArray();
    PartialArray(const ITEM_TYPE init[], int num_used);
    int initialize_array(int num_used);

    int getUsedNumb() const;
    //return NumUsed

    void setArray(const ITEM_TYPE init[], int size);

    int operator [](int index) const;
    friend ostream& operator << (ostream& out, const PartialArray print);

    int _Append(int AppendThis);
    //append an element to the end of the array
    //returns a fail code

    int _Search(int key);
    //search for the item and return the item posoition
    //return error code

    int _ShiftLeft(int ShiftHere);
    //shift the element to the left from this postion
    //returns a fail code

    int _ShiftRight(int ShiftHere);
    //shift the element to the right from this positon
    //returns a fail code

    int _InsertBefore(int insertHere, int insertThis);
    //insert an element before this poistion
    //returns a fail code

    int _InsertAfter(int insertHere, int insertThis);
    //insert an element after this positon
    //returns a fail code

    int _Delete(int deleteHere);
    //delete the element at this position
    //returns a fail code

    void _Sort();
    //sort the array in aceding order;

    void _Revers();
    //reverse the order of element in the array

    void _DeletRepeats();
    //Delete duplicated elemtn in the array


private:
    ITEM_TYPE Array[MAX];
    int UsedNumb;
};

#endif // PARTIALARRAY_H
