#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main()
{
  Stringset words;
  vector<string> alternatives;
  int count = 0;

  loadStringset(words,"wordlist.txt");
  alternatives=spellcheck(words,"lake");

  for (int i=0; i<alternatives.size(); ++i)
  {
    if(alternatives[i]=="lake")
    {
      count++;
    }
  }

  //ASSERT_EQ(count,0);
  if (count != 0)
  {
    std::cout << "expected/correct value for count is 0, actual value when testing " << count << ".\n";
    return 1;
  }

  std::cout << "Passed" << endl;
  return 0;
}