#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <iostream>

using namespace std;

//=============================
//Required Variables:
//=====================
int const MAX = 10;
typedef int ITEM_TYPE;


//===========================================
//Default Functions: input, print, and search
//===========================================
void initialize(ITEM_TYPE a[], int size);
void Print(ITEM_TYPE a[], int size);
int Search(ITEM_TYPE a[], int size, ITEM_TYPE number);


//===============================
//Array Manipulation Functions:
//===============================
int Append(ITEM_TYPE a[], int& size, ITEM_TYPE number);
int ShiftRight(ITEM_TYPE a[], int& size, int position);
int ShiftLeft(ITEM_TYPE a[], int& size, int position);
int InsertBefore(ITEM_TYPE a[], int& size, int position, ITEM_TYPE number);
int InsertAfter(ITEM_TYPE a[], int& size, int position, ITEM_TYPE number);
int Delete(ITEM_TYPE a[], int& size, int position);


//===============================
//More Advanced Array Functions:
//===============================
void Reverse(ITEM_TYPE a[], int size);
void Sort(ITEM_TYPE a[], int size);
void DeleteRepeats(ITEM_TYPE a[], int& size);
void Copy(const ITEM_TYPE original[], ITEM_TYPE duplicate[], int size);

//==========================
//Error checking function:
//==========================
string ErrorDescr(int e);


#endif // ARRAYFUNCTIONS_H
