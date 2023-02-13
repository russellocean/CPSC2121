#include "Grouping.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  bool correct = false;
  int groupNum = 0;
  int count = 0;

  int groupCount = 1;
  GridSquare groupTest[][26] = { {GridSquare(0,4),
                                  GridSquare(0,5),
                                  GridSquare(0,6),
                                  GridSquare(0,7),
                                  GridSquare(0,8),
                                  GridSquare(0,9),
                                  GridSquare(1,9),
                                  GridSquare(2,9),
                                  GridSquare(2,8),
                                  GridSquare(2,7),
                                  GridSquare(3,7),
                                  GridSquare(4,7),
                                  GridSquare(5,7),
                                  GridSquare(5,8),
                                  GridSquare(6,7),
                                  GridSquare(6,6),
                                  GridSquare(6,5),
                                  GridSquare(6,4),
                                  GridSquare(6,3),
                                  GridSquare(5,3),
                                  GridSquare(4,3),
                                  GridSquare(3,3),
                                  GridSquare(3,4),
                                  GridSquare(2,4),
                                  GridSquare(1,4),
                                  GridSquare(1,3)} };
  int sizeTest[] = {26};
  bool groupTestPass[] = {false};

  Grouping input("input2.txt");
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