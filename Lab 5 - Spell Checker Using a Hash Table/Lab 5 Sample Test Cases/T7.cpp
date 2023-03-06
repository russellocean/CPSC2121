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
    words.insert("g");
    words.insert("h");
    words.insert("i");

    //ASSERT_EQ(words.getSize(),16);
    if (words.getSize() != 16)
    {
        std::cout << "expected/correct value for words.getSize() is 16, actual value when testing " << words.getSize() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}