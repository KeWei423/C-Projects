#include "td_array.h"

TD_array::TD_array()
{
    InitialTD();
}

void TD_array::InitialTD()
{
    for(int i=0; i<MAX; i++)
    {
        matrix[i].initialize_array(i+1);
    }
}

PartialArray TD_array:: operator [](int index) const
{
    return matrix[index];
}

PartialArray& TD_array:: operator [](int index)
{
    return matrix[index];
}


ostream& operator <<(ostream& out, const TD_array print)
{
    for(int i=0; i<MAX;i++)
    {
        out<<":";
        for(int j=0; j<=i;j++)
        {
            out<<print.matrix[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}


int TD_array::Append_TA(int row, int appendThis)
{
    return matrix[row]._Append(appendThis);
}

int TD_array::Search_TA(int key, int& pos_r, int& pos_c)
{
    for(int i=0; i<MAX;i++)
    {
        int temp=matrix[i]._Search(key);
        if(temp >=0)
        {
            pos_r=i;
            pos_c=temp;
            return true;
        }
    }
    return false;
}


int TD_array::InsertBefore_TA(int pos_r, int pos_c, int insertThis)
{
    return matrix[pos_r]._InsertBefore(pos_c, insertThis);
}


int TD_array::InsertAfter_TA(int pos_r, int pos_c, int insertThis)
{
    return matrix[pos_r]._InsertAfter(pos_c, insertThis);
}


int TD_array::ShiftLeft_TA(int pos_r, int pos_c)
{
    return matrix[pos_r]._ShiftLeft(pos_c);
}


int TD_array::ShiftRight_TA(int pos_r, int pos_c)
{
    return matrix[pos_r]._ShiftRight(pos_c);
}


int TD_array::Delete_TA(int pos_r, int pos_c)
{
    return matrix[pos_r]._Delete(pos_c);
}

