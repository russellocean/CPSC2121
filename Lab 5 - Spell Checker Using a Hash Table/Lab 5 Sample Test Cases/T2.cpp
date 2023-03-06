#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main()
{
    Stringset words;

    words.insert("a");
    words.insert("b");
    words.insert("c");
    words.insert("d");
    words.insert("e");
    words.insert("f");
    words.remove("b");
    words.remove("d");
    words.remove("f");

    //ASSERT_EQ(words.getNumElems(),3);
    if (words.getNumElems() != 3)
    {
        std::cout << "expected/correct value for words.getNumElems() is 3, actual value when testing " << words.getNumElems() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}