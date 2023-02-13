#include "Grouping.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Grouping input1("input1.txt");
    vector<vector<GridSquare>> groups1;
    groups1 = input1.getGroups();

    Grouping input2("input2.txt");
    vector<vector<GridSquare>> groups2;
    groups2 = input2.getGroups();

    Grouping input3("input3.txt");
    vector<vector<GridSquare>> groups3;
    groups3 = input3.getGroups();

    Grouping input4("input4.txt");
    vector<vector<GridSquare>> groups4;
    groups4 = input4.getGroups();


    //ASSERT_EQ(groups1.size(), 6);
    if (groups1.size() != 6)
    {
        cout << "expected/correct value for groups1.size() is 6, actual value when testing is " << groups1.size() << ".\n";
        return 1;
    }
    //ASSERT_EQ(groups2.size(), 1);
    if (groups2.size() != 1)
    {
        cout << "expected/correct value for groups2.size() is 1, actual value when testing is " << groups2.size() << ".\n";
        return 1;
    }
    //ASSERT_EQ(groups3.size(), 10);
    if (groups3.size() != 10)
    {
        cout << "expected/correct value for groups3.size() is 10, actual value when testing is " << groups3.size() << ".\n";
        return 1;
    }
    //ASSERT_EQ(groups4.size(), 2);
    if (groups4.size() != 2)
    {
        cout << "expected/correct value for groups4.size() is 2, actual value when testing is " << groups4.size() << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}