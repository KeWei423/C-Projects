#include "figure.h"
#include <iostream>
using namespace std;

void Figure::draw()
         {cout<<"Drawing Figure."<<endl;}
void Figure::erase()
         {cout<<"Erasing Figure."<<endl;}

Figure::~Figure(){
    cout<<"Cleaning up Figure"<<endl;
}
