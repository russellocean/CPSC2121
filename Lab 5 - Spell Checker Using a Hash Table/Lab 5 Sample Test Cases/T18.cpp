#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main()
{
    Stringset words;

    loadStringset(words,"wordlist.txt");

    //ASSERT_EQ(words.getNumElems(),170695);
    if (words.getNumElems() != 170695)
    {
        std::cout << "expected/correct value for words.getNumElems() is 170695, actual value when testing " << words.getNumElems() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}