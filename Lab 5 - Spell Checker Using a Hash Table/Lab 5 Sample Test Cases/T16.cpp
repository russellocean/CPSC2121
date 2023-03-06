#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main()
{
    Stringset words;

    loadStringset(words,"wordlist03.txt");

    //ASSERT_EQ(words.getNumElems(),640);
    if (words.getNumElems() != 640)
    {
        std::cout << "expected/correct value for words.getNumElems() is 640, actual value when testing " << words.getNumElems() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}