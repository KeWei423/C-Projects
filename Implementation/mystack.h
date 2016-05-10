/**
 *******************************
 *           Stack             *
 *******************************
 * Stack is FILO with only one end open
 */

#ifndef MYSTACK
#define MYSTACK
#include "../../!IncludeToolKit/LinkedList/mylinkedlist.h"
#include <iostream>
using namespace std;

template<class T>
class myStack
{
public:
    /*constructor*/
    myStack();
    myStack(T item);

    /*Big 3*/
    myStack(const myStack<T>& copyThis);
    ~myStack();
    myStack& operator = (const myStack<T>& copyThis);


    /*Functions*/
    void Push(T pushThis);
    T Pop();
    T Top();
    bool Empty();

    template<class I>
    friend ostream & operator << (ostream& outs, const myStack<I>& PrintMe);

private:
    node<T>* _head;
};

#endif // MYSTACK


template<class I>
ostream & operator << (ostream& outs, const myStack<I>& PrintMe)
{
    node<I>* walker = PrintMe._head;
    outs<<"H-->";
    while(walker)
    {
        outs<<"["<<walker->_item<<"]->";
        walker = walker->_next;
    }
    outs<<"|||"<<endl;
    return outs;
}

//========================================================================

/*--------------------Constructors--------------------*/
template<class T>
myStack<T>::myStack()
{
    _head = NULL;
}


template<class T>
myStack<T>::myStack(T item)
{
    _head = new node<T> (item);
}


/*Big 3*/
template<class T>
myStack<T>::myStack(const myStack<T>& copyThis)
{
    _head = CopyList(copyThis._head->_next);
}

template<class T>
myStack<T>:: ~myStack()
{
    ClearList(_head);
}

template<class T>
myStack<T>& myStack<T>::operator = (const myStack<T>& copyThis)
{
   if(& copyThis != this)
   {
       delete _head;
       node<T>* item = copyThis._head;
       _head = CopyList(item);
   }
   return *this;
}


/*--------------------Functions--------------------*/
/**
 * insert
 */
template<class T>
void myStack<T>::Push(T pushThis)
{
    _head = InsertHead(_head, pushThis);
}


template<class T>
T myStack<T>::Pop()
{
    if(_head==NULL)
    {
        throw 'a';
    }
    T itemPoped = RemoveHead(_head);
    return itemPoped;
}

template<class T>
T myStack<T>::Top()
{
    if(_head)
    {
        return _head->_item;
    }
    else //if link list is empty
    {
        throw 'a';
    }
}


template<class T>
bool myStack<T>::Empty()
{
    if(_head == NULL){
        return true;
    }
    return false;
}







