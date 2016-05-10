/**
 *******************************
 *           Queue             *
 *******************************
 * Queue is FIFO with two end open
 */
#ifndef MYQUEUE
#define MYQUEUE
#include "../../!IncludeToolKit/LinkedList/mylinkedlist.h"
#include <iostream>
using namespace std;

template<class T>
class myQueue
{
public:
    /*constructor*/
    myQueue();
    myQueue(T item);

    /*Big 3*/
    myQueue(const myQueue<T>& copyThis);
    ~myQueue();
    myQueue& operator= (const myQueue<T>& copyThis);


    /*Functions*/
    void Push(T pushThis);
    T Pop();
    T Front();
    T Back();
    bool Empty();
    int Size();

    template<class I>
    friend ostream & operator << (ostream& outs, const myQueue<I>& PrintMe);

private:
    node<T>* _front;
    node<T>* _back;
    int _size;
};



#endif // MYQUEUE

template<class I>
ostream & operator << (ostream& outs, const myQueue<I>& PrintMe)
{
    node<I>* walker = PrintMe._front;
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
myQueue<T>::myQueue()
{
    _front = NULL;
    _back = NULL;
    _size = 0;
}


template<class T>
myQueue<T>::myQueue(T item)
{
    _front = _back = new node<T> (item);
    _size = 0;
}


/*Big 3*/
template<class T>
myQueue<T>::myQueue(const myQueue<T>& copyThis)
{
    node<T>* item = copyThis._front;
    _front = CopyList(item);
//    _front = CopyList(item);
    _back = End(_front);
    _size = copyThis._size;
}

template<class T>
myQueue<T>:: ~myQueue()
{
    ClearList(_front);
    _front = _back = NULL;
    _size = 0;
}

template<class T>
myQueue<T>& myQueue<T>::operator =(const myQueue<T>& copyThis)
{
    if(& copyThis != this)
    {
        ClearList(_front);
        _front = NULL;
        _back = NULL;
        node<T>* item = copyThis._front;
        _front = CopyList(item);
        _back = End(_front);
        _size = copyThis._size;
    }
    return *this;
}


/*--------------------Functions--------------------*/
/**
 * insert
 */
template<class T>
void myQueue<T>::Push(T pushThis)
{
    if(_front == NULL)
    {
        _front = _back = InsertHead(_front,pushThis);
    }
    else
    {
        _back->_next = InsertAfter(_back,pushThis);
        _back = _back->_next;
    }
    _size++;
}


template<class T>
T myQueue<T>::Pop()
{
    if(_back == NULL)
    {
        throw 'a';
    }
    T item = RemoveHead(_front);
    return item;
    _size--;
}

template<class T>
T myQueue<T>::Front()
{
    if(!_front)
    {
        throw 'b';
    }
    return _front->_item;
}

template<class T>
T myQueue<T>::Back()
{
    if(!_back)
    {
        throw 'c';
    }
    return _back->_item;
}

template<class T>
bool myQueue<T>::Empty()
{
    if(_front == NULL){
        return true;
    }
    return false;
}



template<class T>
int myQueue<T>::Size(){
    return _size;
}



