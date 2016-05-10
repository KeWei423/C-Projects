/**
 ***********************************************
 *              myLinkListFunction.h           *
 ***********************************************
 * Templated link list functions
 * 1. statement and definition are in the same file
 *
 */

#ifndef MYLINKEDLIST
#define MYLINKEDLIST
#include <iostream>
using namespace std;

template<class ITEM_TYPE>
struct node
{
    //structure variable
    ITEM_TYPE _item;
    node<ITEM_TYPE>* _next;

    //constructor
    node(): _item(ITEM_TYPE()), _next(NULL){}
    node(ITEM_TYPE i): _item(i), _next(NULL){}

    //structure operator
    template<class E>
    friend ostream& operator << (ostream& outs, const node<E>& PrintMe);
    template<class E>
    friend bool operator < (const node<E>& LHS, const node<E>& RHS);
};


template<class ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head);

template<class ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key, node<ITEM_TYPE>* tail=NULL);

template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE>*& head, ITEM_TYPE newItem);

template<class ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* & target=NULL);

template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& beforeThis, ITEM_TYPE insertThis);

template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>* & afterThis, ITEM_TYPE insertThis);

template<class ITEM_TYPE, typename DUP>
node<ITEM_TYPE>* InsertSortedUnique(node<ITEM_TYPE>*& head, const ITEM_TYPE item, DUP Dup);

template<class ITEM_TYPE>
ITEM_TYPE Delete(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* deleteHere);

template<class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* & head, ITEM_TYPE item);

template<class ITEM_TYPE>
node<ITEM_TYPE>* CopyList(const node<ITEM_TYPE>* & head);

template<class ITEM_TYPE>
ITEM_TYPE RemoveHead(node<ITEM_TYPE>*& head);

template<class ITEM_TYPE>
void ClearList(node<ITEM_TYPE>* & head);

template<class ITEM_TYPE>
node<ITEM_TYPE>* At(node<ITEM_TYPE> *head, int pos);

template<class ITEM_TYPE>
int Test_Length(node<int> *Head);

template<class ITEM_TYPE>
int Length(node<ITEM_TYPE>* head);

template<class ITEM_TYPE>
node<ITEM_TYPE>* End(node<ITEM_TYPE>* head);


//===================================================================================
//===================================================================================

template<class E>
ostream& operator << (ostream& outs, const node<E>& PrintMe)
{
    outs<<"["<<PrintMe._item<<"]"<<endl;
    return outs;
}

template<class E>
bool operator < (const node<E>& LHS, const node<E>& RHS)
{
   E l = LHS._item;
   E r = RHS._item;
    if(l < r)
    {
       return true;
    }
    return false;
}

//===================================================================================
//===================================================================================


/**
 *Print the item in a list in such format H->x->y->z->|||
 */
template<class ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head)
{
    node<ITEM_TYPE>* walker  = head;
       cout<<"H-->";
       while(walker)
       {
           cout<<"["<<walker->_item<<"]->";
           walker = walker->_next;
       }
       cout<<"|||"<<endl;
}


/**
 * tankes a key and return the pointer to the node containing that item
 * Return NULL if not found
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key, node<ITEM_TYPE> *tail)
{
   node<ITEM_TYPE>* walker = head;
   while(walker!=tail)
   {
       if(walker->_item == key)
       {
           return walker;
       }
       walker= walker->_next;
   }
   return NULL;
}


/**
 * Takes a number and inserts it at the bead of the list
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE>* &head, ITEM_TYPE newItem)
{
    node<ITEM_TYPE>* temp;
    temp = new node<ITEM_TYPE>(newItem);
    temp ->_next = head;
    head = temp;
    return temp;
}


/**
 * Takes a pointer to an item in the list (previousToThis)
 * and returns a pointer to the node before the designated node.
 * Returns NULL if the node is the first node in the list.
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* & head, node<ITEM_TYPE>* & target)
{
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* before;
    if(walker == target)
    {
        return NULL;
    }

    while(walker!=target)
    {
        before = walker;
        walker= walker->_next;
    }
    return before;
}


/**
 * Takes a value (insertThis), and a pointer to a node in the list (beforeThis)
 * and inserts the value before the designated node.
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE> *&beforeThis, ITEM_TYPE insertThis)
{
    //1. create a new node and let temp->item == beforeThis->item
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE> (beforeThis->_item);

    //2. temp->next points to what beforeThis is poinring to
    temp->_next = beforeThis->_next;

    // overwrite the new value in beforeThis->item
    beforeThis->_item = insertThis;

    // let beforeThis link to temp
    beforeThis->_next = temp;

    return beforeThis->_next;
}


/**
 * Takes a value (insertThis) and a pointer to a node in the list (afterThis)
 * and inserts the value after the designated node
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>* & afterThis, ITEM_TYPE insertThis)
{
    node<ITEM_TYPE>* temp;
    temp = new node<ITEM_TYPE>(insertThis);
    temp->_next = afterThis->_next;
    afterThis->_next=temp;
    return temp;
}


/**
 * Takes a pointer to a node in the list (deleteThis) and removes that node from the list.
 * Deletes the node and returns the item contained within.
 */
template<class ITEM_TYPE>
ITEM_TYPE Delete(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* deleteHere)
{
    node<ITEM_TYPE> *temp = PreviousNode(head, deleteHere);
    if(temp!=NULL){
        ITEM_TYPE item = deleteHere->_item;
        temp->_next = deleteHere->_next;
        deleteHere = NULL;
        delete deleteHere;
        return item;
    }
    ITEM_TYPE item = RemoveHead(head);
    return item;
}


/**
 * Assumes the list is sorted.
 * Takes a value (item) and returns a pointer to the node after which the item belongs in the list.
 * Returns NULL if the item belongs at the head of the list.
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* & head, ITEM_TYPE item)
{
    node<ITEM_TYPE>* walker = head->_next;
    node<ITEM_TYPE>* prevWalker = head;
    if(prevWalker->_item >= item){
        return NULL;
    }
    while(walker){
        if(walker->_item > item){
            return prevWalker;
        }
        prevWalker = prevWalker->_next;
        walker = walker->_next;
    }
    return prevWalker;
}


/**
 * Takes a list (head) and returns a pointer to a linked list that is a copy of this list.
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* CopyList (node<ITEM_TYPE>* & head)
{
    //1. creat head walker
    node<ITEM_TYPE>* headWalker = head;
    //2. create new node and its walker
    node<ITEM_TYPE>* dup = NULL;
    InsertHead(dup, headWalker->_item);
    node<ITEM_TYPE>* dupWalker = dup;
    //3. making headWalker points to the next one
    headWalker= headWalker->_next;
    //4. copy elements
    while(headWalker)
    {
       node<ITEM_TYPE>* pos = SearchList(dupWalker, dupWalker->_item);
       InsertAfter(pos, headWalker->_item);
       headWalker= headWalker->_next;
       dupWalker = dupWalker->_next;
    }
//    PrintList(dup);
    return dup;
}


template<class ITEM_TYPE>
ITEM_TYPE RemoveHead(node<ITEM_TYPE>*& head)
{
    ITEM_TYPE item = head->_item;
    node<ITEM_TYPE>* first = head;
    head = head->_next;
    delete first;
    first = NULL;
    return item;
}


/**
 * Takes a list (head) and deletes all the nodes in the list
 */
template<class ITEM_TYPE>
void ClearList(node<ITEM_TYPE>* & head)
{
    while(head)
    {
        node<ITEM_TYPE>* walker = head;
        walker = NULL;
        delete walker;
        head = head ->_next;
    }
}


/**
 * Takes a position (n) and returns a pointer to the nth position in the list
 */
template<class ITEM_TYPE>
node<ITEM_TYPE>* At(node<ITEM_TYPE> *head, int pos)
{
    node<ITEM_TYPE>* walker = head;
    int counter = 0;
    while(walker)
    {
        if(counter == pos)
        {
            return walker;
        }
        walker =walker->_next;
        counter++;
    }
    return NULL;
}


/**
 * Find the length of a given link list
 */
template<class ITEM_TYPE>
int Length(node<ITEM_TYPE>* head)
{
    ITEM_TYPE length = 1;
    node<ITEM_TYPE>* walker = head;
    while(walker)
    {
        length++;
        walker=walker->_next;
    }
    return length;
}


template<class ITEM_TYPE>
node<ITEM_TYPE>* End(node<ITEM_TYPE>* head)
{
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* other = head->_next;
    if(other == NULL){
        return walker;
    }
    while(other)
    {
        walker =walker->_next;
        other = other->_next;
    }
    return walker;
}


template<class ITEM_TYPE, typename DUP>
node<ITEM_TYPE>* InsertSortedUnique(node<ITEM_TYPE>*& head, const ITEM_TYPE item, DUP Dup){
    if(head == NULL){
        return InsertHead(head, item);
    }
    else{
        node<ITEM_TYPE>* InsertHere = WhereThisGoes(head, item);
        node<ITEM_TYPE>* findThis = SearchList(head, item);
        if(findThis != NULL){
            Dup(findThis->_item, item);
        }
        else{
            if(InsertHere == NULL){
                return InsertHead(head, item);
            }
            else{
                return InsertAfter(InsertHere, item);
            }
        }
    }
    return head;
}


#endif // MYLINKEDLIST
