#ifndef MYSORTEDLIST
#define MYSORTEDLIST
#include "../../!IncludeToolKit/Linked List/mylinkedlist.h"
#include <iostream>
using namespace std;

template<class T>
class mySorted
{
public:
    /*constructor*/
    mySorted();
    mySorted(T item);

    /*Big 3*/
    mySorted(const mySorted<T>& copyThis);
    ~mySorted();
    mySorted& operator = (const mySorted<T>& copyThis);


    /*Functions*/
    void Insert(T pushThis);
    bool Empty();

    template<class I>
    friend ostream & operator << (ostream& outs, const mySorted<I>& PrintMe);

private:
    node<T>* _head;
};


template<class I>
ostream & operator << (ostream& outs, const mySorted<I>& PrintMe)
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
mySorted<T>::mySorted()
{
    _head = NULL;
}


template<class T>
mySorted<T>::mySorted(T item)
{
    _head = new node<T> (item);
}


/*Big 3*/
template<class T>
mySorted<T>::mySorted(const mySorted<T>& copyThis)
{
    _head = CopyList(copyThis._head->_next);
}

template<class T>
mySorted<T>:: ~mySorted()
{
    ClearList(_head);
}

template<class T>
mySorted<T>& mySorted<T>::operator = (const mySorted<T>& copyThis)
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
void mySorted<T>::Insert(T insertThis)
{/*
        if ((!head) || (head->data >= data)) {
            return InsertHead(head, data);
        }
        else {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            for (Node *walker = head; walker->next; walker = walker->next) {
                if (walker->next->data >= data) {
                    Node *temp = walker->next;
                    walker->next = newNode;
                    newNode->next = temp;
                    return head;
                }
            }
            return InsertTail(head, data);
        }
    }*/
    if(_head == NULL)
    {
        InsertHead(_head, insertThis);
    }
    else
    {
        node<T>* goHere = WhereThisGoesD(_head, insertThis);
        node<T>* end = End(_head);
        if(!goHere)
        {
            InsertHead(_head, insertThis);
        }
        else
        {
            InsertAfter(end, insertThis);
        }
    }
}




template<class T>
bool mySorted<T>::Empty()
{
    return !_head;
}
#endif // MYSORTEDLIST

