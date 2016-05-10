#ifndef TD_ARRAY_H
#define TD_ARRAY_H
#include "../../Array Class Project/ClassFiles/partialarray.h"
#include "iostream"

using namespace std;

class TD_array
{
public:
    TD_array();
    void InitialTD();

    PartialArray operator [](int index) const;
    PartialArray& operator [](int index);

    friend ostream& operator << (ostream& out, const TD_array print);

    int Append_TA(int row, int appendThis);
    int Search_TA(int key, int& pos_r, int& pos_c);
    int ShiftLeft_TA(int pos_r, int pos_c);
    int ShiftRight_TA(int pos_r, int pos_c);
    int InsertBefore_TA(int pos_r,int pos_c, int insertThis);
    int InsertAfter_TA(int pos_r, int pos_c, int insertThis);
    int Delete_TA(int pos_r, int pos_c);



private:
    PartialArray matrix[MAX];
};

#endif // TD_ARRAY_H
