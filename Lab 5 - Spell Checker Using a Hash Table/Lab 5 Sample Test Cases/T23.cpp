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
    if(alternatives[i]=="bake" ||
      alternatives[i]=="cake" ||
      alternatives[i]=="fake" ||
      alternatives[i]=="make" ||
      alternatives[i]=="rake" ||
      alternatives[i]=="sake" ||
      alternatives[i]=="take" ||
      alternatives[i]=="wake" ||
      alternatives[i]=="leke" ||
      alternatives[i]=="like" ||
      alternatives[i]=="lace" ||
      alternatives[i]=="lade" ||
      alternatives[i]=="lame" ||
      alternatives[i]=="lane" ||
      alternatives[i]=="late" ||
      alternatives[i]=="lave" ||
      alternatives[i]=="laze" ||
      alternatives[i]=="laky")
    {
      count++;
    }
  }

  //ASSERT_EQ(count,18);
  if (count != 18)
  {
    std::cout << "expected/correct value for count is 18, actual value when testing " << count << ".\n";
    return 1;
  }

  std::cout << "Passed" << endl;
  return 0;
}