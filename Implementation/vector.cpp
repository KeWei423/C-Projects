#include "vector.h"

Vector::Vector():length(1), str(NULL)
{
    //intend to leave blank
}


Vector::Vector(int size)
{
    length = size;
    str = Allocate(length);
    Initialize(str);
}

Vector::Vector(string *ptr, int size): length(size)
{
    str=Allocate(length);
    Copy(ptr, str, length);
}



//===========
// the big 3
//===========
Vector::Vector(const Vector& source) //copy constructor
{
    length = source.length;
    str = Allocate(length);
    Copy(source.str, str, length);
}


Vector::~Vector()
{
//    cout<<"Fire Destructor"<<endl;
    delete []str;
    str = NULL;
}


Vector& Vector:: operator = (const Vector& RHS)
{
    //check if the LHS is the RHS
    if(&RHS != this)
    {
        delete [] str;
        length = RHS.length;
        str = Allocate(length);
        Copy (RHS.str, str, length);
    }
    return *this;
}


void Vector::Copy(string* source, string* dest, int length)
{
    string* sourceWalker = source;
    for(int i=0; i<length; i++)
    {
        *dest = *sourceWalker;
        sourceWalker++;
        dest++;
    }
}


void Vector::Print()
{
    string* strWalker = str;
    for(int i=0; i<length; i++)
    {
        cout<<"|"<<*strWalker<<"|";
        strWalker++;
    }
}



void Vector::AddEntry(string item)
{
    str = Add(str, length, item);
}


void Vector::DeleteEntry(string item)
{
    str = Delete(str, length,item);

}
