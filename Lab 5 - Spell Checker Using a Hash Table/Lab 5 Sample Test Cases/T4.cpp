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

    //ASSERT_EQ(words.find("g"),false);
    if (words.find("g") != false)
    {
        std::cout << "expected/correct value for words.find(\"g\") is false (0), actual value when testing " << words.find("g") << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}