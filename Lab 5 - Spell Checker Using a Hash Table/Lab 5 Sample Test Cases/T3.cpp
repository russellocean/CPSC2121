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

    //ASSERT_EQ(words.find("e"),true);
    if (words.find("e") != true)
    {
        std::cout << "expected/correct value for words.find(\"e\") is true (1), actual value when testing " << words.find("e") << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}