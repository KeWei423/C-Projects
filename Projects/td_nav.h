#ifndef TD_NAV_H
#define TD_NAV_H
#include "../../Array Class Project/ClassFiles/td_array.h"
#include <iostream>
using namespace std;

class TD_Nav
{
public:
    TD_Nav();
    TD_Nav(int col);

    friend ostream& operator << (ostream& out, TD_Nav print);

    int Up_TN();
    int Down_TN();
    int Left_TN();
    int Right_TN();

    int Insert_TN(int insertThis);
    int Delete_TN();
    int Append_TN(int appendThis);
    int Search_TN(int item);

private:
    TD_array TwoDNav;
    int rowCursor;
    int colCursor;
};

#endif // TD_NAV_H
