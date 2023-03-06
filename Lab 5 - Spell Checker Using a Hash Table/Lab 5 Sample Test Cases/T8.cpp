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
    words.insert("a");
    words.insert("c");
    words.insert("e");
    words.insert("c");

    //ASSERT_EQ(words.getNumElems(),5);
    if (words.getNumElems() != 5)
    {
        std::cout << "expected/correct value for words.getNumElems() is 5, actual value when testing " << words.getNumElems() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}