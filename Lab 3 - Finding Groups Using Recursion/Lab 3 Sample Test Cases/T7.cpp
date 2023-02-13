#include "Grouping.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  bool correct = false;
  int groupNum = 0;
  int totalSize = 0;

  int groupCount = 10;
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
      if(sizeTest[g] == groups[i].size())
      {
        groupTestPass[g] = true;
      }
    }
  }

  correct = groupTestPass[0];
  for (int g=1; g<groupCount; g++)
  {
    correct = correct && groupTestPass[g];
  }

  for (int i=0; i<groups.size(); i++)
  {
    totalSize += groups[i].size();
  }

  if (totalSize != 40)
  {
    correct = false;
    cout << "total number of square(s) counted: " << totalSize << ", expected: 40.\n";
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