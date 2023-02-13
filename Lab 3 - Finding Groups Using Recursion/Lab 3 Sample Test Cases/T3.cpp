#include "Grouping.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  bool correct = false;
  int groupNum = 0;
  int count = 0;

  int groupCount = 10;
  GridSquare groupTest[][14] = { {GridSquare(0,2)},
                                {GridSquare(0,8),
                                  GridSquare(1,8),
                                  GridSquare(1,9)},
                                {GridSquare(1,1)},
                                {GridSquare(1,3)},
                                {GridSquare(1,5),
                                  GridSquare(1,6),
                                  GridSquare(2,5)},
                                {GridSquare(2,2)},
                                {GridSquare(3,7),
                                  GridSquare(3,8),
                                  GridSquare(4,7),
                                  GridSquare(4,6),
                                  GridSquare(4,5),
                                  GridSquare(5,5),
                                  GridSquare(5,6),
                                  GridSquare(5,7),
                                  GridSquare(6,7),
                                  GridSquare(6,6),
                                  GridSquare(6,5),
                                  GridSquare(6,4),
                                  GridSquare(7,6),
                                  GridSquare(7,7)},
                                {GridSquare(4,0), 
                                  GridSquare(4,1), 
                                  GridSquare(4,2), 
                                  GridSquare(5,2), 
                                  GridSquare(6,2), 
                                  GridSquare(6,1), 
                                  GridSquare(6,0), 
                                  GridSquare(5,0)},
                                {GridSquare(8,0), 
                                  GridSquare(9,0), 
                                  GridSquare(9,1)},
                                {GridSquare(8,9), 
                                  GridSquare(9,9), 
                                  GridSquare(9,8), 
                                  GridSquare(9,7), 
                                  GridSquare(9,6)} };
  int sizeTest[] = {1, 3, 1, 1, 3, 1, 14, 8, 3, 5};
  bool groupTestPass[] = {false, false, false, false, false,
                          false, false, false, false, false};

  Grouping input("input3.txt");
  vector<vector<GridSquare>> groups;
  groups = input.getGroups();

  for (int g=0; g<groupCount; g++)
  {
    for (int i=0; i<groups.size(); i++)
    {
      for (int j=0; j<groups[i].size(); j++)
      {
        if (groupTest[g][0] == groups[i][j])
        {
          groupNum=i;
        }
      }
    }

    count = 0;
    for (int s=0; s<sizeTest[g]; s++)
    {
      for (int i=0; i<groups[groupNum].size(); i++)
      {
        if (groupTest[g][s] == groups[groupNum][i])
        {
          count++;
        }
      }
      if (count == sizeTest[g])
      {
        groupTestPass[g] = true;
      }
    }
    if (groupTestPass[g] == false)
    {
      cout << "group " << g << " has " << count << " square(s), expected/correct amount: " << sizeTest[g] << endl;
    }
  }

  correct = groupTestPass[0];
  for (int g=1; g<groupCount; g++)
  {
    correct = correct && groupTestPass[g];
  }


  //ASSERT_EQ(correct, true);
  if (correct != true)
  {
    cout << "expected/correct value true (1), actual value when testing " << correct << ".\n";
    return 1;
  }
  cout << "Passed" << endl;
  return 0;
}