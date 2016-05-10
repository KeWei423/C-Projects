#ifndef ITERATOR
#define ITERATOR
#include"../../!IncludeToolKit/LinkedList/mylinkedlist.h"
template<class ITEM_TYPE>
class Iterator
{
public:
    template <class T>
    friend class List;

    Iterator();
    Iterator(node<ITEM_TYPE>* ptr);

    Iterator operator ++ ();
    ITEM_TYPE & operator *();
    bool operator ==( const Iterator<ITEM_TYPE> &RHS);
    Iterator & operator +=(int num);

private:
    node<ITEM_TYPE>* p;
};

template<class ITEM_TYPE>
Iterator<ITEM_TYPE>::Iterator()
{
    p = NULL;
}

template<class ITEM_TYPE>
Iterator<ITEM_TYPE>::Iterator(node<ITEM_TYPE>* ptr)
{
    p = ptr;
}

template<class ITEM_TYPE>
Iterator<ITEM_TYPE> Iterator<ITEM_TYPE>::operator ++()
{
    p = p->_next;
    return Iterator(p);
}


template<class ITEM_TYPE>
ITEM_TYPE& Iterator<ITEM_TYPE>::operator *()
{
    return p->_item;
}

template<class ITEM_TYPE>
bool Iterator <ITEM_TYPE>::operator ==(const Iterator<ITEM_TYPE> &first)
{
   return first.p->_item == p->_item ? true:false;
}

//move the iterator from giving number
template<class ITEM_TYPE>
Iterator<ITEM_TYPE>& Iterator<ITEM_TYPE> ::operator += (int num)
{
    for(int i = 0 ; i< num ; i++){
        p = p->next;
    }
}

#endif // ITERATOR

