/*
 * Name: Russell Welch
 * Date Submitted: 2/13/23
 * Lab Section: 001
 * Assignment Name: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Constructor that reads a file and processes it using findGroup
//Takes in the name of the file to be read
Grouping::Grouping(string fileName) : grid{}, groups()
{
    //Open the input file
    ifstream inputFile(fileName);

    //Check if the file was successfully opened
    if (!inputFile) {
        cout << "Error: file not found!" << endl;
        return;
    }

    //Read the file into the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            inputFile >> c;
            grid[i][j] = (c == '.') ? 0 : 1; //Convert the character to a 0 or 1 and store it in the grid
        }
    }

    //Find the groups using findGroup
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) { //If the current square is occupied
                vector<GridSquare> newGroup; //Create a new vector to store the locations of the occupied squares in this group
                findGroup(i, j); //Find the group of connected squares containing the current square
                groups.push_back(newGroup); //Add the new group to the groups vector
            }
        }
    }
}

//Recursive function that finds a group of connected squares
//Takes in the row and column indices of the current square being processed
void Grouping::findGroup(int r, int c)
{
    //Check if the row and column indices are out of bounds or if the current square is unoccupied
    if (r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == 0) {
        return; //If so, return and do not process this square
    }

    grid[r][c] = 0; //Mark the current square as unoccupied in the grid

    //If the groups vector is empty, add a new vector to it to store the locations of the occupied squares in this new group
    if (groups.empty()) {
        vector<GridSquare> newGroup;
        groups.push_back(newGroup);
    }

    //Push the location of the current square to the back of the last group in the groups vector
    groups.back().push_back(GridSquare(r, c));

    //Recurse on the neighboring squares in the grid
    findGroup(r-1, c);
    findGroup(r+1, c);
    findGroup(r, c-1);
    findGroup(r, c+1);
}


//Simple main function to test Grouping
//Be sure to comment out main() before submitting
//int main()
//{
//    Grouping input1("input1.txt");
//    input1.printGroups();
//
//    return 0;
//}

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}