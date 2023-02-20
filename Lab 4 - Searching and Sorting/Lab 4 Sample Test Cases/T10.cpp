#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Searches.h"

int main()
{
    std::vector<std::string> stringTest {"greetings", "yall", "earthlings", "take", "me", "to", "your", "leader"};
    std::sort(stringTest.begin(), stringTest.end());
    std::string tester = "take";
    int a = binarySearch(stringTest, tester);
    //ASSERT_EQ(a,4);
    if (a != 4)
    {
        std::cout << "expected/correct value for a is 4, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}