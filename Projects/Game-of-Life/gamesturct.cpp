#include "gamesturct.h"
#include <iomanip>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;


/*********************************************
 *               Constructor                 *
 * make a 10x10 platform with 5 active cells *
 *********************************************/
GameSturct::GameSturct()
{
    Init();
//    World[1][1]=1;
//    World[2][1]=1;
//    World[3][1]=1;
    for(int i=0; i<5; i++)
    {
        Activator();
    }
}


/**************************************
 *              Randomizer            *
 **************************************/
int GameSturct::Random(int lo, int hi)
{
    int range = hi-lo +1;
    int randomNumber = lo +(rand() % range);
    return randomNumber;
}


/**************************************************
 *              Initializers/Cell killer          *
 **************************************************/
void GameSturct::Init()
{
    for (int r=0; r<HEIGHT;r++)
    {
        for(int c=0; c<WIDTH; c++)
        {
            World[r][c]=DEAD;
        }
    }
}


void GameSturct::Init(int row, int col)
{
    World[row][col]=DEAD;
}


/**************************************************
 *                  Cell Activator                *
 **************************************************/
//Active a dead cell to live
void GameSturct::Activator()
{
    int row, col;
    row=Random(1,(HEIGHT-2));
    col=Random(1,(WIDTH-2));
    World[row][col]=LIVE;
}


//Active a spcifice dead cell
void GameSturct::Activator(int rol, int col)
{
    World[rol][col]=LIVE;
}


/**************************************
 *              Print                 *
 **************************************/
void GameSturct::Print()
{
    for (int i=0; i<HEIGHT;i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            cout<<setw(3)<<World[i][j];
        }
    cout<<endl;
    }
}


ostream& operator << (ostream& outs, const GameSturct& source)
{
    for (int i=0; i<HEIGHT;i++)
    {

        for(int j=0; j<WIDTH; j++)
        {
            outs<<setw(3)<<source.World[i][j];
        }
    outs<<endl;
    }
    return outs;
}


/*********************************************
 *             Generator fucntion            *
 *********************************************/
void GameSturct::Next()
//Reproducting tne next generation of World
{

    int temp[HEIGHT][WIDTH];
    Copy(temp);
    CheckEdge(temp);
    for(int r=1; r<HEIGHT-1; r++)
    {
        for(int c=1; c<WIDTH-1; c++)
        {
            int neighb=CheckNeighb(temp, r, c);
            World[r][c]=Rule(temp[r][c], neighb);
        }
    }
}


/*********************************************
 *                Game Rule                  *
 *********************************************/
int GameSturct::Rule(int value, int neighb)
{
    //Rules:
    /*live cell with < 2 live neighbor dies
     *live cell with only 2 or 3 live neighbors lives, else dies
     * dead cell with exactly 3 live neighors becomes a live cell
     */
    int life=DEAD;

    if((value==LIVE) && (neighb<2))
    {
        life=DEAD;
    }
    if((value==LIVE) && ((neighb==2)||(neighb==3)))
    {
        life=LIVE;
    }
    if((value==LIVE) && (neighb>3))
    {
        life=DEAD;
    }
    if((value==DEAD) &&(neighb==3))
    {
        life=LIVE;
    }
    return life;
}


/*********************************************
 *              Generator Steps              *
 *********************************************/
void GameSturct::CheckEdge(int temp[][WIDTH])
//The first row and the laswe row are adjacent and same for the column. So a cell on the first row will have
//neighbors on the last
{
    //change colum:
    for(int r=0; r<WIDTH; r++)
    {
        temp[r][WIDTH-1]=temp[r][1];
        temp[r][0]=temp[r][WIDTH-2];
    }

    //change row:
    for(int c=0; c<HEIGHT; c++)
    {
        temp[HEIGHT-1][c]=temp[1][c];
        temp[0][c]=temp[HEIGHT-2][c];
    }

    temp[HEIGHT-1][WIDTH-1]=temp[1][1];
    temp[HEIGHT-1][0]=temp[1][WIDTH-2];
    temp[0][0]=temp[HEIGHT-2][WIDTH-2];
    temp[0][WIDTH-1]=temp[HEIGHT-2][1];
}


//check the neighbor to add up live cells
int GameSturct::CheckNeighb(int world[HEIGHT][WIDTH], int row, int col)
{
    //check each cell's 8 surrounding cell to count for live cells
    //if the cells surronding is in the gutter area, make interchange be 0 and max-2;
    //add live cells to total
    //return the total
    int counter=0;
    for(int r=(row-1);r<(row+2);r++)
    {
        for(int c=(col-1); c<(col+2); c++)
        {
            if(world[r][c]==LIVE)
                counter++;
        }
    }
    counter=counter-world[row][col];
    return counter;
}


//copy the one generation to the next
void GameSturct::Copy(int temp[HEIGHT][WIDTH])
{
    for(int r=0; r<HEIGHT; r++)
    {
        for(int c=0; c<WIDTH; c++)
        {
            temp[r][c]=World[r][c];
        }
    }
}


/*********************************************
 *              Same and Load                *
 *********************************************/
void GameSturct:: Save(int row1, int col1, int row2, int col2)
//save is the output file
{
    //declare
    ofstream outFile;
    char outFile_name[MAX];

    //name file
    cout<<"Save the file name as: "; cin>>outFile_name;

    //open
    outFile.open(outFile_name);

    //test for fail
    if(outFile.fail())
    {
        cout<<"*****"<<outFile_name<<" is fail to open *****"<<endl;
        cin.get();
        exit(0); //fail to open ofstream file
    }

    //write:
    int h=row2-row1;
    int w=col2-col1;
    outFile<<h<<" "<<w<<endl;
    for(int r=row1; r<=row2; r++)
    {
        for(int c=col1; c<=col2; c++)
        {
            outFile<<World[r][c]<<" ";
        }
        outFile<<endl;
    }

    //close:
    outFile.close();
}

void GameSturct::Load(int x, int y)
{
    //declare
    ifstream inFile;
    char inFile_name[MAX];
    int h, w;

    //input the name the user would like to open
    cout<<"Enter File name to load: "; cin>>inFile_name;

    //open
    inFile.open(inFile_name);

    //check for fail
    if(inFile.fail())
    {
        cout<<"***** There is no such file with name "<<inFile_name<<" *****"<<endl;
        cin.get();
        exit(0); //fail to find the file
    }

    //read:
    inFile>>h>>w;
//    cout<<"h: "<<h<<" w:"<<w<<endl;
    for(int r=x; r<=(h+x); r++)
    {
        for(int c=y; c<=(w+y); c++)
        {
            inFile>>World[r][c];
        }
//        cout<<endl;
    }


    //close
    inFile.close();
}
