/*
 * Name: Russell Welch
 * Date Submitted: 2/13/23
 * Lab Section: 001
 * Assignment Name: Finding Groups Using Recursion
 */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare(); //Default constructor, (0,0) square
        GridSquare(int r, int c); //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const;
        int getRow(); //return row value
        int getCol(); //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        const int GRID_SIZE = 10;
        vector<vector<GridSquare>> groups;
    public:
        Grouping(); //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups(); //Displays grid's groups of squares
        vector<vector<GridSquare>> getGroups(); //Needed in unit tests
};