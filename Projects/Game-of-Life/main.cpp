//File: Game of Life
//Author: Ke Wei
//Ojbective: Create a simulation of John Conway's game of life using 2Darray
//           Each elementof the array represent a cell that is either alive or dead
//           Once an initial state is set up, the program will generate new genration based on a specific rule
//Purpose:
/* Design: build a function hierarchy that will make managing this process easier. low level function that will act as tools on top of which higher levle fuctions will be build upon
 * Flow of Control: the process of creating consercutive genration will be near impossible to do whithout using various nested loops
 * Functions: There will be many functions used to break down the project into specific tasks that must be performed each time a new genration is generated
 * Input/Output: files will be used to import and export a pattern or gernation's current states
 * Array: 2D array is used to represent a generation of cells with each element of the array representing an individual cell
 */

//Date created: 23 November 2015
//Last Date modified:

//Notes:
/* Save the initial cordinate in the Save() function because you need to know where to start at;
 * Then Same the patter/screen along in the file

 * When load the file, the file output the content one by one so declare x, y, height and weith in order for the first 4 values you put in the file
 */

#include "../../14GameOfLife/GameClass/gamesturct.h"
#include <iostream>
//#include <fstream>
#include <time.h>

using namespace std;
void Menu();
void ProcessEvent(GameSturct init);

int main()
{
    cout<<endl;
    srand((unsigned)time(0));
    GameSturct perform;


    cout<<"====================================================="<<endl;
    cout<<perform<<endl;
    Menu();
    ProcessEvent(perform);
    cout <<"=======================END=========================="<<endl;
    return 0;
}


void Menu()
{
    cout<<"[N]ext: Display the next generation.\n"
        <<"[G]o: loop consecutively for 10 generations\n"
        <<"[P]ause: pause at a specific generation\n"
        <<"[S]ave Patterns\n"
        <<"Save S[C]reen\n"
        <<"[L]oad Pattern\n"
        <<"Loa[D] Screen\n"
        <<"[R]andom: Add 50 random live cells \n"
        <<"[B]ring to life\n"
        <<"[K]ill a specific cell\n"
        <<"Kill [A]ll\n"
        <<"E[X]it"<<endl;
}

void ProcessEvent(GameSturct init)
{
    int generation, r1, c1, r2, c2;
    char choice;
    bool quit=false;
    char comma;
    while(!quit)
    {
        cout<<": "; cin>>choice;
        switch(toupper(choice))
        {
            case 'N':
                init.Next();
                cout<<"Next generation:\n"<<init<<endl;
                break;
            case 'G':
                for(int i=0; i<10; i++)
                {
                    init.Next();
                    cout<<"Generation "<<(i+1)<<" :\n"<<init<<endl;
                }
                break;
            case 'P':
                cout<<"#: "; cin>>generation;
                for(int i=0; i<generation; i++)
                {
                    init.Next();
                    cout<<"Generation "<<(i+1)<<" :\n"<<init<<endl;
                }
                break;
            case 'S':
                cout<<"Save Pattern: "<<endl;
                cout<<"(r1, c1): "; cin>>r1>>comma>>c1;
                cout<<"(r2, c2): "; cin>>r2>>comma>>c2;
                init.Save(r1, c1, r2, c2);
                cout<<"Pattern Saved"<<endl;
                break;
            case 'C':
                cout<<"Save Screen: "<<endl;
                init.Save();
                cout<<"Screen Saved"<<endl;
                break;
            case 'L':
                cout<<"Load Patter: "<<endl;
                cout<<"(r1, c1): "; cin>>r1>>comma>>c1;
//                cout<<"(r2, c2): "; cin>>r2>>comma>>c2;
                init.Load(r1,r2);
                cout<<init<<endl;
                break;
            case 'D':
                cout<<"Load Screen: "<<endl;
                init.Load();
                cout<<init<<endl;
                break;
            case 'R':
                cout<<"Make 50 random cells alive"<<endl;
                for(int i=0; i<50; i++)
                {
                    init.Activator();
                }
                cout<<init<<endl;
                break;
            case 'B':
                cout<<"Bring one cell alive"<<endl;
                cout<<"Row, Col: "; cin>>r1>>comma>>c1;
                init.Activator(r1,c1);
                cout<<init<<endl;
                break;
            case 'K':
                cout<<"Kill one cell"<<endl;
                cout<<"Row, Col: "; cin>>r1>>comma>>c1;
                init.Init(r1,c1);
                cout<<init<<endl;
                break;
            case 'A':
                cout<<"Kill All cells"<<endl;
                init.Init();
                cout<<init<<endl;
                break;
            case 'X':
                quit=true;
                break;
            default:
                cout<<"["<<choice<<"]"<<" is not a valid choice."<<endl;
                cin.get();
                break;
        }
    }
}
