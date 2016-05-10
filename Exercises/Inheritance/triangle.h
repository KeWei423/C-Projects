#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include <iostream>
class Triangle: public Figure{
 public:
    void draw();
    void erase(); 
    ~Triangle();
};

class Circle: public Figure{
public:
   void erase(){std::cout<<"Circle erase()"<<std::endl;}


};

#endif // TRIANGLE_H
