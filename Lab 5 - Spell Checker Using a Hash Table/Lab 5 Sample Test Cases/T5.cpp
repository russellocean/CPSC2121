#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main()
{
    Stringset words;

    //ASSERT_EQ(words.getSize(),4);
    if (words.getSize() != 4)
    {
        std::cout << "expected/correct value for words.getSize() is 4, actual value when testing " << words.getSize() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}