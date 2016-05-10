#ifndef LIST_H
#define LIST_H

#include "../../!IncludeToolKit/LinkedList/mylinkedlist.h"
#include "../../!IncludeToolKit/Iterator/iterator.h"
template <class ITEM_TYPE>
class List
{
public:
    List();
    List(const List<ITEM_TYPE> & copyMe);
    List & operator = (const List<ITEM_TYPE> & target);
    ~List();

    Iterator<ITEM_TYPE> Begin();
    Iterator<ITEM_TYPE> Tail();
    Iterator<ITEM_TYPE> Insert(ITEM_TYPE i);
    Iterator<ITEM_TYPE> Search(ITEM_TYPE i);
    Iterator<ITEM_TYPE> Previous(Iterator<ITEM_TYPE> target);
    Iterator<ITEM_TYPE> InsertAftr(Iterator <ITEM_TYPE> InsertHere,ITEM_TYPE item);
    Iterator<ITEM_TYPE> InsertBfr(Iterator <ITEM_TYPE> InsertHere, ITEM_TYPE item);
    Iterator<ITEM_TYPE> WhereThisGoes(ITEM_TYPE i);
    ITEM_TYPE & operator [](int position);
    void Print();
private:
    node<ITEM_TYPE>* _head;
};


template <class ITEM_TYPE>
List<ITEM_TYPE>::List()
{
    _head = NULL;
}


template<typename ITEM_TYPE>
List<ITEM_TYPE> ::List(const List<ITEM_TYPE> & copyMe)
{
    _head = NULL;
    node <ITEM_TYPE> *walker = copyMe._head;
    _head = CopyList(walker);
}


template<typename ITEM_TYPE>
List <ITEM_TYPE> ::~List()
{
    ClearList(_head);
    _head= NULL;
}


template<typename ITEM_TYPE>
List <ITEM_TYPE> & List <ITEM_TYPE> :: operator = (const List<ITEM_TYPE> & target){
    _head = NULL;
    if(&target != this){
        node <ITEM_TYPE> *walker = target._head;
        _head = CopyList(walker);
    }
    return *this;
}


template <class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>::Insert(ITEM_TYPE i)
{
    node<ITEM_TYPE>* mark /*= InsertHead(_head, i)*/;
    if(!_head)
    {
        mark = InsertHead(_head, i);
    }
    else{
        mark =InsertAfter(_head, i);
    }
    return Iterator<ITEM_TYPE>(mark);
}


template <class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>::Search(ITEM_TYPE i)
{
    node<ITEM_TYPE>* mark = SearchList(_head, i);
    return Iterator<ITEM_TYPE>(mark);
}


template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print()
{
    PrintList(_head);
}


template <class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>:: Begin()
{
    //return new?
    return Iterator<ITEM_TYPE> (_head);
}


template <class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>:: Tail()
{
    node<ITEM_TYPE>* mark = End(_head);
    return Iterator<ITEM_TYPE> (mark);
}


template <class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>::Previous(Iterator<ITEM_TYPE> target)
{
    node<ITEM_TYPE>* mark = PreviousNode(_head, target.p);
    return Iterator<ITEM_TYPE> (mark);
}

template<class ITEM_TYPE>
Iterator<ITEM_TYPE> List <ITEM_TYPE>::InsertAftr(Iterator <ITEM_TYPE> InsertHere, ITEM_TYPE item)
{
    node<ITEM_TYPE>* mark = InsertHere.p;
    node<ITEM_TYPE>* hold = InsertAfter(mark,item);
    return Iterator <ITEM_TYPE> (hold);
}


template<class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>::InsertBfr(Iterator <ITEM_TYPE> InsertHere, ITEM_TYPE item)
{
    node<ITEM_TYPE>* mark = InsertHere.p;
    node<ITEM_TYPE>* hold = InsertBefore(mark, item);
    return Iterator<ITEM_TYPE> (hold);
}

template<class ITEM_TYPE>
Iterator<ITEM_TYPE> List<ITEM_TYPE>::WhereThisGoes(ITEM_TYPE i)
{
    node<ITEM_TYPE>* mark = WhereThisGoesA(_head, i);
    return Iterator<ITEM_TYPE> (mark);
}

template<class ITEM_TYPE>
ITEM_TYPE & List <ITEM_TYPE> ::operator [](int position)
{
    node <ITEM_TYPE> *hold = At(_head,position);
    return hold->_item;
}

#endif // LIST_H
