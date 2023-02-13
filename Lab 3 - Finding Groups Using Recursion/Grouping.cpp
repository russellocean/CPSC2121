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

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName) 
{
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        int row = 0;
        while (getline(file, line)) {
            for (int col = 0; col < GRID_SIZE; col++) {
                if (line[col] == '.') {
                    grid[row][col] = 0;
                } else {
                    grid[row][col] = 1;
                }
            }
            row++;
        }
        file.close();
    }

    //process the grid to find the groups
    for (int r = 0; r < GRID_SIZE; r++) {
        for (int c = 0; c < GRID_SIZE; c++) {
            if (grid[r][c] == 1) {
                findGroup(r, c);
            }
        }
    }
}

void Grouping::findGroup(int r, int c)
{
    //check if the current cell is occupied and within bounds of the grid
    if (grid[r][c] == 1 && r >= 0 && r < GRID_SIZE && c >= 0 && c < GRID_SIZE) {
        //mark the cell as visited
        grid[r][c] = 2;

        //add the cell to the current group
        vector<GridSquare> currentGroup;
        currentGroup.push_back(GridSquare(r, c));
        
        //recursively search the neighboring cells
        findGroup(r-1, c); //up
        findGroup(r+1, c); //down
        findGroup(r, c-1); //left
        findGroup(r, c+1); //right
    }
}


//Simple main function to test Grouping
//Be sure to comment out main() before submitting
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}

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