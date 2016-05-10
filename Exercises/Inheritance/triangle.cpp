#include "triangle.h"
#include <iostream>
using namespace std;

void Triangle::draw()
      {cout<<"Drawing Triangle."<<endl;}
void Triangle::erase()
      {cout<<"Erasing Triangle."<<endl;}
Triangle::~Triangle(){
    cout<<"Cleaning up Triangle"<<endl;
}
