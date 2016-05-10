#ifndef GAMESTURCT_H
#define GAMESTURCT_H
#include "../../14GameOfLife/GameClass/gameoflife_const.h"
#include <fstream>
#include <iostream>
using namespace std;

class GameSturct
{
public:
    //constructor
    GameSturct();
    GameSturct(int term);

    //Randomizer
    int Random(int lo, int hi);

    //Initializers/Cell killer
    void Init();
    void Init(int row, int col);

    //Cell Activator
    void Activator();
    void Activator(int row, int col);

    //print
    void Print();
    friend ostream& operator <<(ostream& outs, const GameSturct& source);

    //Game functions
    void CheckEdge(int temp[HEIGHT][WIDTH]);
    int Rule(int value, int neighb);
    int CheckNeighb(int world[HEIGHT][WIDTH], int row, int col);
    void Next();
    void Copy(int temp[HEIGHT][WIDTH]);

    //Save and Load
    void Save(int row1=1, int col1=1, int row2=HEIGHT-1, int col2=WIDTH-1);    //save is the output file
    void Load(int x=1, int y=1);    //load is the input file


private:
    int World[HEIGHT][WIDTH];
};

#endif // GAMESTURCT_H
