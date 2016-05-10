#include "td_nav.h"
#include <iomanip>
TD_Nav::TD_Nav()
{
    TwoDNav=TD_array();
    rowCursor=0;
    colCursor=0;
}



ostream& operator << (ostream& out, const TD_Nav print)
{
    for(int i=0; i<MAX; i++)
    {
        if((print.rowCursor == i) && (print.colCursor <0)&&(print.TwoDNav[i].getUsedNumb()==0))
        {
            out<<"[:]"<<endl;

        }
        else
        {
            out<<":";
            for(int j=0; j<print.TwoDNav[i].getUsedNumb(); j++)
            {
                if((i==print.rowCursor)&&(j==print.colCursor))
                {
                    out<<setw(5)<<"["<<print.TwoDNav[i][j]<<"]"<<" ";
                }
                else
                {
                    out<<setw(5)<<print.TwoDNav[i][j]<<" ";
                }
            }
            out<<endl;
        }
    }
    return out;
}


int TD_Nav::Append_TN(int appendThis)
{
    return  TwoDNav.Append_TA(rowCursor, appendThis);

}


int TD_Nav::Search_TN(int item)
{
    return TwoDNav.Search_TA(item, rowCursor, colCursor);
}


int TD_Nav::Up_TN()
{
    if(rowCursor>0)
    {
        rowCursor=rowCursor-1;
        return true;
    }
    else
    {
        rowCursor=0;
        return false;
    }

}

int TD_Nav::Down_TN()
{
    if(rowCursor< MAX-1)
    {
       rowCursor = rowCursor+1;
        return true;
    }
    else if(rowCursor == -1)
    {
        rowCursor = 1;
        return true;
    }
    else
    {
        rowCursor = 0;
        return false;
    }
}


int TD_Nav::Left_TN()
{
    if(colCursor >0)
    {
        colCursor=colCursor-1;
    }
    else
    {
        colCursor=0;
    }
    return colCursor;
}

int TD_Nav::Right_TN()
{
    if(colCursor<MAX-1)
    {
        colCursor=colCursor+1;
        return colCursor;
    }
    else
    {
        colCursor =0;
    }
    return colCursor ;
}



int TD_Nav::Insert_TN(int insertThis)
{
    return TwoDNav.InsertBefore_TA(rowCursor, colCursor, insertThis);
}


int TD_Nav::Delete_TN()
{
    int temp =TwoDNav.Delete_TA(rowCursor,colCursor);
    colCursor--;
    return temp;
}

