#include <iostream>
#include <vector>

using namespace std;
#include "rectangle.h"
#include "triangle.h"
int main(){
    cout<<endl<<endl<<"==================="<<endl;
    vector<Figure*> figArrays;

    figArrays.push_back(new Triangle);
    figArrays.push_back(new Rectangle);

    for(int i = 0; i < (int) figArrays.size(); i++){
        figArrays[i]->draw();
        cout<<endl;

        figArrays[i]->erase();
        cout<<endl;

        delete figArrays[i];
        cout<<endl;
    }

//      cout<<endl<<"Triangle:"<<endl;
//      Tri = new Triangle;
//      Tri-> draw();
//      Tri-> erase();

//      cout<<endl<<"Rectangle: "<<endl;
//      Rect = new Rectangle;
//      Rect-> draw();
//      Rect-> erase();

//     cout<<endl<<"Circle: "<<endl;
//     Figure* cir = new Circle;
//     cir->erase();
//     cir->draw();
//        Triangle* tTest = new Triangle;
//        tTest -> draw();

//    cout<<endl<<endl<<"Deleting Triangle: "<<endl;
//    delete Tri;

//    cout<<endl<<"Deleting Rectangle: "<<endl;
//    delete Rect;

//    cout<<endl<<"Deleting Circle: "<<endl;
//    delete cir;

    cout<<endl<<endl<<"==========END========= "<<endl;
        cout<<endl;
   return 0;
}
