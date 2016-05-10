#include "navigationarray.h"

NavigationArray::NavigationArray()
{
    cursor = 0;
}

NavigationArray:: NavigationArray(const int init[], int size)
{
    thisArray=PartialArray(init, size);
    cursor=0;
}



//------------------
//Service functions
//------------------
int NavigationArray:: Left()
//decrement the cursor to the previous position
//return fail code
{
    if (cursor<0)
    {
        return false;
        //left most position, empty array
    }
    else
    {
        cursor --;
        return true;
    }
}

int NavigationArray:: Right()
//increment the cursor to the next positon
//return fail code
{
    if(cursor < thisArray.getUsedNumb()-1)
    {
        cursor++;
        return true;
    }
    else
    {
        return false;
    }
}


int NavigationArray:: Insert_AN(int insertMe)
//insert item at the current positon
//return fail code
{
    return thisArray._InsertBefore(cursor, insertMe);
}


int NavigationArray:: Append_AN(int appendMe)
//append an item at the end
//return fail code
{
    return thisArray._Append(appendMe);
}


int NavigationArray:: Delete_AN()
//delete curent position
//return fail code
{
    return thisArray._Delete(cursor);

}

int NavigationArray:: Search_AN(int key)
//Search the key and return postion
//or return fail code
{
    return thisArray._Search(key);
}

ostream& operator << (ostream& out, const NavigationArray& print)
{
    out<<"{";
    for(int i=0;i<print.thisArray.getUsedNumb(); i++)
    {

        if(i==print.cursor)
        {
            out<<"["<<print.thisArray[i]<<"]"<<" ";
        }
        else
        {
            out<<print.thisArray[i]<<" ";
        }
    }
    out<<"}";
    return out;
}


