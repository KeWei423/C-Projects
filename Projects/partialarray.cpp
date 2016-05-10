#include "partialarray.h"

PartialArray::PartialArray()
{
    UsedNumb=0;
}

PartialArray::PartialArray(const ITEM_TYPE init[], int num_used)
{
    UsedNumb=num_used;
    ::Copy(init, Array, UsedNumb);
}


int PartialArray:: getUsedNumb() const
{
    return UsedNumb;
}


ostream& operator << (ostream& out, const PartialArray print)
{
    out<<"{ ";
    for(int i=0; i<print.UsedNumb;i++)
    {
        out<<print[i]<<" ";
    }
    out<<"}";
    return out;
}


int PartialArray::_Append(int AppendThis)
{
    return ::Append(Array, UsedNumb, AppendThis);
}


int PartialArray::_Search(int key)
{
    return ::Search(Array, UsedNumb, key);
}


int PartialArray:: initialize_array(int num_used)
{
    ::initialize(Array, num_used);
    UsedNumb=num_used;
    return UsedNumb;
}


int PartialArray:: operator [](int index) const
{
    return Array[index];
}


int PartialArray:: _ShiftLeft(int ShiftHere)
{
    return ::ShiftLeft(Array, UsedNumb, ShiftHere);
}


int PartialArray:: _ShiftRight(int ShiftHere)
{
    return::ShiftRight(Array, UsedNumb, ShiftHere);
}


int PartialArray:: _InsertBefore(int insertHere, int insertThis)
{
    return ::InsertBefore(Array, UsedNumb, insertHere, insertThis);
}


int PartialArray:: _InsertAfter(int insertHere, int insertThis)
{
    return ::InsertAfter(Array, UsedNumb, insertHere, insertThis);
}


int PartialArray:: _Delete(int deleteHere)
{
    return ::Delete(Array, UsedNumb, deleteHere);
}


void PartialArray:: _Sort()
{
    ::Sort(Array, UsedNumb);
}


void PartialArray:: _Revers()
{
    ::Reverse(Array, UsedNumb);
}


void PartialArray:: _DeletRepeats()
{
    ::DeleteRepeats(Array, UsedNumb);
}



