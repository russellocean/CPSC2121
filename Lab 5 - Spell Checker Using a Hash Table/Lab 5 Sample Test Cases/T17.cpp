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

    //ASSERT_EQ(words.find("aah"),true);
    if (words.find("aah") != true)
    {
        std::cout << "expected/correct value for words.find(\"aah\") is true (1), actual value when testing " << words.find("aah") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("zoo"),true);
    if (words.find("zoo") != true)
    {
        std::cout << "expected/correct value for words.find(\"zoo\") is true (1), actual value when testing " << words.find("zoo") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("cat"),true);
    if (words.find("cat") != true)
    {
        std::cout << "expected/correct value for words.find(\"cat\") is true (1), actual value when testing " << words.find("cat") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("the"),true);
    if (words.find("the") != true)
    {
        std::cout << "expected/correct value for words.find(\"the\") is true (1), actual value when testing " << words.find("the") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("mix"),true);
    if (words.find("mix") != true)
    {
        std::cout << "expected/correct value for words.find(\"mix\") is true (1), actual value when testing " << words.find("mix") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("abc"),false);
    if (words.find("abc") != false)
    {
        std::cout << "expected/correct value for words.find(\"abc\") is false (0), actual value when testing " << words.find("abc") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("xyz"),false);
    if (words.find("xyz") != false)
    {
        std::cout << "expected/correct value for words.find(\"xyz\") is false (0), actual value when testing " << words.find("xyz") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("aaa"),false);
    if (words.find("aaa") != false)
    {
        std::cout << "expected/correct value for words.find(\"aaa\") is false (0), actual value when testing " << words.find("aaa") << ".\n";
        return 1;
    }
    //ASSERT_EQ(words.find("zzz"),false);
    if (words.find("zzz") != false)
    {
        std::cout << "expected/correct value for words.find(\"zzz\") is false (0), actual value when testing " << words.find("zzz") << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}