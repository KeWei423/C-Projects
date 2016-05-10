#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H
#include <iostream>

using namespace std;

class CounterType
{
    public:
        //constructors
        CounterType();
        CounterType(int start);

        //Mutator
        void set(int start);

        //Accessor
        int get();

        //member functions
        int up();
        int down();

        //error functions
        int Error();
        void Clear();
        string ErrorDescr(int e);


    private:
        int count;
        int error;
};

#endif // COUNTERTYPE_H
