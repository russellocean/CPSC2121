#include "Grouping.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  bool correct = false;
  int groupNum = 0;
  int count = 0;

  int groupCount = 2;
  GridSquare groupTest[][16] = { {GridSquare(1,3),
                                  GridSquare(2,3),
                                  GridSquare(2,2),
                                  GridSquare(2,4),
                                  GridSquare(2,5),
                                  GridSquare(1,5),
                                  GridSquare(2,6),
                                  GridSquare(3,5),
                                  GridSquare(4,5),
                                  GridSquare(4,4),
                                  GridSquare(4,3),
                                  GridSquare(3,3),
                                  GridSquare(4,2),
                                  GridSquare(5,3),
                                  GridSquare(4,6),
                                  GridSquare(5,5)},
                                {GridSquare(6,7),
                                  GridSquare(7,7),
                                  GridSquare(7,6),
                                  GridSquare(7,5),
                                  GridSquare(7,4),
                                  GridSquare(7,3),
                                  GridSquare(7,2),
                                  GridSquare(7,1),
                                  GridSquare(8,3),
                                  GridSquare(9,3),
                                  GridSquare(9,4),
                                  GridSquare(9,5),
                                  GridSquare(9,6),
                                  GridSquare(7,8),
                                  GridSquare(7,9),
                                  GridSquare(8,9)} };
  int sizeTest[] = {16, 16};
  bool groupTestPass[] = {false, false};

  Grouping input("input4.txt");
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