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

    loadStringset(words,"wordlist.txt");
    alternatives=spellcheck(words,"lake");

    //ASSERT_EQ(alternatives.size(),18);
    if (alternatives.size() != 18)
    {
        std::cout << "expected/correct value for alternatives.size() is 18, actual value when testing " << alternatives.size() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}