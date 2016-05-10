#ifndef NODE
#define NODE

///////////////////////////////////////
///      construct a node           ///
///////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct node{
    //instances:
    T _item;
    node<T>* _next;

    //ctor:
    node(): _item(T()), _next(NULL){}
    node(T item): _item(item), _next(NULL){}
    node(T item, node<T>* next): _item(item), _next(next){}
    node(node<T>* next): _item(T()), _next(next){}

    //methods:
    template<class U>
    friend ostream& operator << (ostream& outs, const node<U>& printMe);
    template<class U>
    friend bool operator == (const node<U>& LHS, const node<U>& RHS) ;
    template<class U>
    friend bool operator != (const node<U>& LHS, const node<U>& RHS) ;
    template<class U>
    friend bool operator < (const node<U>& LHS, const node<U>& RHS) ;
    template<class U>
    friend bool operator <= (const node<U>& LHS, const node<U>& RHS) ;
    template<class U>
    friend bool operator > (const node<U>& LHS, const node<U>& RHS) ;
    template<class U>
    friend bool operator >= (const node<U>& LHS, const node<U>& RHS) ;
};


//---------------------------------------------------------------------------------
template<class U>
ostream& operator << (ostream& outs, const node<U>& printMe){
    outs<<"["<<printMe._item<<"]"<<endl;
    return outs;
}


template<class U>
bool operator == (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item == RHS._item);
}


template<class U>
bool operator != (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item != RHS._item);
}


template<class U>
bool operator < (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item < RHS._item);
}


template<class U>
bool operator <= (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item <= RHS._item);
}


template<class U>
bool operator > (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item > RHS._item);
}


template<class U>
bool operator >= (const node<U>& LHS, const node<U>& RHS) {
    return (LHS._item >= RHS._item);
}


#endif // NODE

